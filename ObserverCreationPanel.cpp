#include "AudioPlaybackObserver.hpp"
#include "NothingObserver.hpp"
#include "ObserverCreationPanel.hpp"
#include <wx/event.h>
#include <wx/filedlg.h>
#include <wx/gtk/filedlg.h>

// NOLINTNEXTLINE(bugprone-throwing-static-initialization) // idk what to do with this
wxDEFINE_EVENT(wxEVT_PANEL_UPDATED, wxCommandEvent);

void ObserverCreationPanel::onFileChange(wxCommandEvent& event)
{
    auto* const ptr_observer = dynamic_cast<AudioPlaybackObserver*>(m_observer.get());
    if (ptr_observer == nullptr)
    {
        return;
    }
    const auto RESULT = ptr_observer->setSoundFile(event.GetString().ToStdString());
    if (RESULT.has_value())
    {
        m_valid = true;
        m_textCtrlSoundFilePath->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        m_textCtrlSoundFilePath->SetToolTip(wxEmptyString);
    }
    else
    {
        m_valid = false;
        m_textCtrlSoundFilePath->SetBackgroundColour(wxColour("tomato"));
        m_textCtrlSoundFilePath->SetToolTip(RESULT.error());
    }
    notifyParent();
}
void ObserverCreationPanel::onButtonOpenClick([[maybe_unused]] wxCommandEvent& event)
{
    wxFileDialog dialog(
      this,
      "Select Sound File",
      defaultDirectory,
      wxEmptyString,
      AudioPlaybackObserver::GetFileExtensionList().getWildcardForFileDialogue(true, true),
      wxDEFAULT_DIALOG_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dialog.ShowModal() == wxID_OK)
    {
        m_textCtrlSoundFilePath->SetValue(dialog.GetPath());
        defaultDirectory = dialog.GetDirectory().ToStdString();
    }
}
void ObserverCreationPanel::onCBLoopAudioChange(wxCommandEvent& event)
{
    auto* const ptr_observer = dynamic_cast<AudioPlaybackObserver*>(m_observer.get());
    if (ptr_observer == nullptr)
    {
        return;
    }
    ptr_observer->setLoopAudio(event.IsChecked());
    notifyParent();
}

void ObserverCreationPanel::onRBDoNothing([[maybe_unused]] wxCommandEvent& event)
{
    setObserver(std::make_unique<NothingObserver>());
    updateRadioButtonControls(ERadioButtonState::DO_NOTHING);
}
void ObserverCreationPanel::onRBAudio([[maybe_unused]] wxCommandEvent& event)
{
    auto observer = std::make_unique<
      AudioPlaybackObserver>(m_mainForm, m_textCtrlSoundFilePath->GetValue().ToStdString(), m_cbLoopAudio->GetValue());
    setObserver(std::move(observer));
    updateRadioButtonControls(ERadioButtonState::AUDIO);
}
void ObserverCreationPanel::onRBCommand([[maybe_unused]] wxCommandEvent& event)
{
    // TODO: command observer

    updateRadioButtonControls(ERadioButtonState::COMMAND);
    throw std::runtime_error("onRBCommand not implemented");
}
void ObserverCreationPanel::onCommandChange(wxCommandEvent& event)
{
    event.GetString();
    notifyParent();
    throw std::runtime_error("onCommandChange not implemented");
}
void ObserverCreationPanel::onButtonCommandClick([[maybe_unused]] wxCommandEvent& event)
{
    notifyParent();
    throw std::runtime_error("onButtonCommandClick not implemented");
}
void ObserverCreationPanel::onRBPopup([[maybe_unused]] wxCommandEvent& event)
{
    // TODO: popup observer

    updateRadioButtonControls(ERadioButtonState::POPUP);
    throw std::runtime_error("onRBPopup not implemented");
}

void ObserverCreationPanel::updateRadioButtonControls(const ERadioButtonState STATE)
{
    wxCommandEvent event{};
    switch (STATE)
    {
        case ERadioButtonState::DO_NOTHING:
        {
            m_textCtrlCommand->Enable(false);
            m_btnCommand->Enable(false);
            m_textCtrlSoundFilePath->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
            m_textCtrlSoundFilePath->Enable(false);
            m_btnFileOpen->Enable(false);
            m_cbLoopAudio->Enable(false);
            m_valid = true;
            break;
        }
        case ERadioButtonState::COMMAND:
        {
            m_textCtrlCommand->Enable(true);
            m_btnCommand->Enable(true);
            m_textCtrlSoundFilePath->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
            m_textCtrlSoundFilePath->Enable(false);
            m_btnFileOpen->Enable(false);
            m_cbLoopAudio->Enable(false);
            event.SetString(m_textCtrlCommand->GetValue());
            onCommandChange(event);
            break;
        }
        case ERadioButtonState::POPUP:
        {
            m_textCtrlCommand->Enable(false);
            m_btnCommand->Enable(false);
            m_textCtrlSoundFilePath->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
            m_textCtrlSoundFilePath->Enable(false);
            m_btnFileOpen->Enable(false);
            m_cbLoopAudio->Enable(false);
            m_valid = true;
            break;
        }
        case ERadioButtonState::AUDIO:
        {
            m_textCtrlCommand->Enable(false);
            m_btnCommand->Enable(false);
            m_textCtrlSoundFilePath->Enable(true);
            m_btnFileOpen->Enable(true);
            m_cbLoopAudio->Enable(true);
            event.SetString(m_textCtrlSoundFilePath->GetValue());
            onFileChange(event);
            break;
        }
    }
    notifyParent();
}
// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
ObserverCreationPanel::ObserverCreationPanel(wxWindow* ptr_parent, wxWindow* ptr_mainForm)
        : ObserverCreationPanelBase(ptr_parent), m_mainForm(ptr_mainForm)
{
    setObserver(std::make_unique<NothingObserver>());
}
auto ObserverCreationPanel::isValid() const -> bool
{
    return m_valid;
}
auto ObserverCreationPanel::getObserver() -> IObserver&
{
    return *m_observer;
}
void ObserverCreationPanel::notifyParent()
{
    wxCommandEvent event(wxEVT_PANEL_UPDATED, GetId());
    event.SetEventObject(this);
    GetEventHandler()->ProcessEvent(event);
}
void ObserverCreationPanel::setObserver(std::unique_ptr<IObserver> observer)
{
    m_observer = std::move(observer);

    {
        auto* const ptr_nothingObserver = dynamic_cast<NothingObserver*>(m_observer.get());
        if (ptr_nothingObserver != nullptr)
        {
            m_radioBtnNothing->SetValue(true);
            updateRadioButtonControls(ERadioButtonState::DO_NOTHING);
        }
    }
    {
        auto* const ptr_audioPlaybackObserver = dynamic_cast<AudioPlaybackObserver*>(m_observer.get());
        if (ptr_audioPlaybackObserver != nullptr)
        {
            m_radioBtnAudio->SetValue(true);
            m_textCtrlSoundFilePath->SetValue(ptr_audioPlaybackObserver->getSoundFile().string());
            m_cbLoopAudio->SetValue(ptr_audioPlaybackObserver->getLoopAudio());
            updateRadioButtonControls(ERadioButtonState::AUDIO);
        }
    }
    // TODO: Command
    // TODO: Popup
}

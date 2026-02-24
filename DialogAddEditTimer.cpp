#include "AudioPlaybackObserver.hpp"
#include "DialogAddEditTimer.hpp"
#include <chrono>

DialogAddEditTimer::DialogAddEditTimer(wxWindow* const ptr_parent, CountdownTimer timer)
        : DialogAddEditTimerBase(ptr_parent), m_timer(std::move(timer))
{
    IObserver* const ptr_observer = m_timer.getObserver().get();
    // TODO: Set radio boxes to correct state and update field enabled for all fields
    {
        auto* const ptr_audioPlaybackObserver = dynamic_cast<AudioPlaybackObserver*>(ptr_observer);
        if (ptr_audioPlaybackObserver != nullptr)
        {
            m_textCtrlSoundFilePath->SetValue(ptr_audioPlaybackObserver->getSoundFile().string());
            m_cbLoopAudio->SetValue(ptr_audioPlaybackObserver->getLoopAudio());
        }
    }

    m_textCtrlTimerName->SetValue(m_timer.getName());
    const std::chrono::duration<double> TIME               = m_timer.getDuration();

    constexpr int                       SECONDS_PER_HOUR   = 3'600;
    constexpr int                       SECONDS_PER_MINUTE = 60;

    const int                           HOUR = std::min(static_cast<int>(TIME.count()) / SECONDS_PER_HOUR, 23);
    const int MINUTE                         = (static_cast<int>(TIME.count()) % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
    const int SECOND                         = static_cast<int>(TIME.count()) % SECONDS_PER_MINUTE;

    m_timePicker->SetTime(HOUR, MINUTE, SECOND);
}
[[nodiscard]]
auto DialogAddEditTimer::extractTimer() -> CountdownTimer&&
{
    return std::move(m_timer);
}

void DialogAddEditTimer::onNameChange(wxCommandEvent& event)
{
    m_timer.setName(event.GetString().ToStdString());
}
void DialogAddEditTimer::onTimeChange(wxDateEvent& event)
{
    const auto TIME = std::chrono::hours(event.GetDate().GetHour())
                      + std::chrono::minutes(event.GetDate().GetMinute())
                      + std::chrono::seconds(event.GetDate().GetSecond());
    m_timer.setDuration(TIME);
}
void DialogAddEditTimer::onFileChange(wxCommandEvent& event)
{
    auto* const ptr_observer = dynamic_cast<AudioPlaybackObserver*>(m_timer.getObserver().get());
    if (ptr_observer == nullptr)
    {
        return;
    }
    const auto RESULT = ptr_observer->setSoundFile(event.GetString().ToStdString());
    if (RESULT.has_value())
    {
        m_sdbSizerOK->Enable(true);
        m_textCtrlSoundFilePath->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        m_textCtrlSoundFilePath->SetToolTip(wxEmptyString);
    }
    else
    {
        m_sdbSizerOK->Enable(false);
        m_textCtrlSoundFilePath->SetBackgroundColour(wxColour("tomato"));
        m_textCtrlSoundFilePath->SetToolTip(RESULT.error());
    }
}
void DialogAddEditTimer::onButtonOpenClick([[maybe_unused]] wxCommandEvent& event)
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
void DialogAddEditTimer::onCBLoopAudioChange(wxCommandEvent& event)
{
    auto* const ptr_observer = dynamic_cast<AudioPlaybackObserver*>(m_timer.getObserver().get());
    if (ptr_observer == nullptr)
    {
        return;
    }
    ptr_observer->setLoopAudio(event.IsChecked());
}

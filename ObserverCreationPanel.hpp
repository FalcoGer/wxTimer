#pragma once

#include "AudioPlaybackObserver.hpp"
#include "NothingObserver.hpp"
#include "wxObserverCreationPanelBase.h"
#include <wx/event.h>

// NOLINTNEXTLINE(readability-identifier-naming) // sticking to wx naming convention here
wxDECLARE_EVENT(wxEVT_PANEL_UPDATED, wxCommandEvent);

class ObserverCreationPanel : public ObserverCreationPanelBase
{
  private:
    std::unique_ptr<IObserver> m_observer;
    bool                       m_valid {false};
    wxWindow*                  m_mainForm;

    // NOLINTNEXTLINE(concurrency-mt-unsafe, bugprone-throwing-static-initialization)
    static inline std::string defaultDirectory {getenv("HOME")};

    enum class ERadioButtonState : std::uint8_t
    {
        DO_NOTHING,
        COMMAND,
        POPUP,
        AUDIO
    };

    void updateRadioButtonControls(const ERadioButtonState STATE);

  public:
    // NOLINTNEXTLINE(bugprone-easily-swappable-parameters) // What can I do?
    ObserverCreationPanel(wxWindow* ptr_parent, wxWindow* ptr_mainForm) : ObserverCreationPanelBase(ptr_parent), m_mainForm(ptr_mainForm)
    {
        setObserver(std::make_unique<NothingObserver>());
    }

    [[nodiscard]]
    auto isValid() const -> bool
    {
        return m_valid;
    }

    [[nodiscard]]
    auto getObserver() -> IObserver&
    {
        return *m_observer;
    }

    void notifyParent()
    {
        wxCommandEvent event(wxEVT_PANEL_UPDATED, GetId());
        event.SetEventObject(this);
        ProcessWindowEvent(event);
    }

    void setObserver(std::unique_ptr<IObserver> observer)
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
        // TODO: Set radio boxes to correct state and update field enabled for all fields
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
  protected:
    void onFileChange(wxCommandEvent& event) override;
    void onButtonOpenClick(wxCommandEvent& event) override;
    void onCBLoopAudioChange(wxCommandEvent& event) override;
    void onRBDoNothing(wxCommandEvent& event) override;
    void onRBCommand(wxCommandEvent& event) override;
    void onCommandChange(wxCommandEvent& event) override;
    void onButtonCommandClick(wxCommandEvent& event) override;
    void onRBPopup(wxCommandEvent& event) override;
    void onRBAudio(wxCommandEvent& event) override;
};

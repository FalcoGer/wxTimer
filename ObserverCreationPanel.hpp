#pragma once
#include "IObserver.hpp"
#include "TimerBase.hpp"
#include "wxObserverCreationPanelBase.h"
#include <memory>
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
        AUDIO,
        LOG
    };

    void updateRadioButtonControls(const ERadioButtonState STATE);

  public:
    // NOLINTNEXTLINE(bugprone-easily-swappable-parameters) // What can I do?
    ObserverCreationPanel(wxWindow* ptr_parent, wxWindow* ptr_mainForm);

    [[nodiscard]]
    auto isValid() const -> bool;

    [[nodiscard]]
    auto getObserver() -> IObserver&;

    void notifyParent();

    void setObserver(std::unique_ptr<IObserver> observer);

  protected:
    void onSoundFileChange(wxCommandEvent& event) override;
    void onButtonSoundFileOpenClick(wxCommandEvent& event) override;
    void onCBLoopAudioChange(wxCommandEvent& event) override;
    void onRBDoNothing(wxCommandEvent& event) override;
    void onRBCommand(wxCommandEvent& event) override;
    void onCommandChange(wxCommandEvent& event) override;
    void onButtonCommandClick(wxCommandEvent& event) override;
    void onRBPopup(wxCommandEvent& event) override;
    void onRBAudio(wxCommandEvent& event) override;
    void onRBLog2File(wxCommandEvent& event) override;
    void onLogFileChange(wxCommandEvent& event) override;
    void onButtonLogFileOpenClick(wxCommandEvent& event) override;
    void onLogExpiredTextChange(wxCommandEvent& event) override;
    void onCBLogExpiredNL(wxCommandEvent& event) override;
    void onLogResetTextChange(wxCommandEvent& event) override;
    void onCBLogResetNL(wxCommandEvent& event) override;
};

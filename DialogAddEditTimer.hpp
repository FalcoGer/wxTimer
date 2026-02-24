#pragma once

#include "CountdownTimer.hpp"
#include "WxTimerBase.h"
#include <cstdint>
#include <cstdlib>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/string.h>

class DialogAddEditTimer : public DialogAddEditTimerBase
{
  private:
    CountdownTimer m_timer;
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
    explicit DialogAddEditTimer(wxWindow* const ptr_parent, CountdownTimer timer);

    [[nodiscard]]
    auto extractTimer() -> CountdownTimer&&;

  protected:
    void onNameChange(wxCommandEvent& event) override;
    void onTimeChange(wxDateEvent& event) override;
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

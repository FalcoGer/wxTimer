#pragma once

#include "CountdownTimer.hpp"
#include "wxDialogAddEditTimerBase.h"
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/string.h>

class DialogAddEditTimer : public DialogAddEditTimerBase
{
  private:
    CountdownTimer m_timer;

  public:
    explicit DialogAddEditTimer(wxWindow* const ptr_parent, CountdownTimer timer);

    [[nodiscard]]
    auto extractTimer() -> CountdownTimer&&;

  protected:
    void onNameChange(wxCommandEvent& event) override;
    void onTimeChange(wxDateEvent& event) override;
    void onObserverUpdated([[maybe_unused]] wxCommandEvent& event);
};

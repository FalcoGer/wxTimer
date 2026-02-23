#pragma once

#include "StopwatchTable.hpp"
#include "TimerTable.hpp"
#include "WxTimerBase.h"
#include <chrono>

class WxTimerFrame : public WxTimerBase
{
  private:
    using TimePoint = std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds>;
    enum class EStopwatchState : bool
    {
        STOPPED,
        RUNNING
    };
    EStopwatchState m_stopwatchState = EStopwatchState::STOPPED;
    StopwatchTable* m_stopwatchTable;
    TimerTable*     m_timerTable;

  public:
    explicit WxTimerFrame(wxWindow* ptr_parent);

    virtual ~WxTimerFrame() = default;

  protected:
    // ========================================================
    // FRAME
    // =======================================================
    void onTimerElapsed(wxTimerEvent& event) override;

    // ========================================================
    // STOPWATCH PAGE
    // ========================================================
    void onClickStopwatchStartLap(wxCommandEvent& event) override;
    void onClickStopwatchReset(wxCommandEvent& event) override;

    // ==========================================================================
    // TIMER PAGE
    // ==========================================================================

    void onAddTimerClick(wxCommandEvent& event) override;
    void onEditTimerClick(wxCommandEvent& event) override;
    void onDeleteTimerClick(wxCommandEvent& event) override;
    void onStartStopTimerClick(wxCommandEvent& event) override;
    void onCancelTimerClick(wxCommandEvent& event) override;
    void onTimerGridSelectionChanged(wxGridEvent& event) override;
    void onTimerGridCellChange(wxGridEvent& event) override;
};

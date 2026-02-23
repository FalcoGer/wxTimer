#pragma once

#include <cstddef>
#include <wx/debug.h>
#include <wx/generic/grid.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif
#include "Timer.hpp"
#include <vector>

class TimerTable : public wxGridTableBase
{
  private:
    std::vector<Timer> m_timers;
    void               sortTimers();

    wxGridCellAttr* m_attrName;
    wxGridCellAttr* m_attrTime;
    wxGridCellAttr* m_attrActive;

  public:
    TimerTable();
    ~TimerTable();

    TimerTable(const TimerTable&) = delete;
    auto operator= (const TimerTable&) -> TimerTable& = delete;
    TimerTable(TimerTable&&) = delete;
    auto operator= (TimerTable&&) -> TimerTable& = delete;

    auto GetNumberRows() -> int override;
    auto GetNumberCols() -> int override;    // Name, Time, Active
    //NOLINTNEXTLINE(bugprone-easily-swappable-parameters) // it can't be helped
    auto GetValue(int row, int col) -> wxString override;
    // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
    void SetValue(int row, int col, const wxString& value) override;
    auto GetAttr(int row, int col, wxGridCellAttr::wxAttrKind kind) -> wxGridCellAttr* override;

    void setTimer(int row, Timer&& timer);

    [[nodiscard]]
    auto        getTimerStarted(int row) const -> bool;
    auto        getTimerCopy(int row) -> Timer { return m_timers.at(static_cast<std::size_t>(row)); }
    auto        getTimers() -> std::vector<Timer>& { return m_timers; }
    void        addTimer(Timer&& timer);
    // NOLINTNEXTLINE(google-default-arguments) // It can't be helped. Not my interface.
    auto        DeleteRows(std::size_t pos, std::size_t numRows = 1) -> bool override;
    auto        GetColLabelValue(int col) -> wxString override;
    static auto GetColumnSizes(const wxGrid& grid) -> wxGridSizesInfo;
};

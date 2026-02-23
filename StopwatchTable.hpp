#pragma once

#include <cstddef>
#include <wx/generic/grid.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif

#include <chrono>
#include <vector>

class StopwatchTable : public wxGridTableBase
{
  private:
    using TimePoint = std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds>;
    std::vector<TimePoint> m_stopwatchTimes;

  public:
    auto GetNumberRows() -> int override;
    auto        GetNumberCols() -> int override;

    //NOLINTNEXTLINE(bugprone-easily-swappable-parameters) // it can't be helped
    auto        GetValue(int row, int col) -> wxString override;

    // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
    void SetValue([[maybe_unused]] int row, [[maybe_unused]] int col, [[maybe_unused]] const wxString& value) override;

    // NOLINTNEXTLINE(google-default-arguments) // It can't be helped. Not my interface.
    auto        AppendRows(std::size_t numRows = 1) -> bool override;

    // NOLINTNEXTLINE(google-default-arguments) // It can't be helped. Not my interface.
    auto        DeleteRows(std::size_t pos, std::size_t numRows = 1) -> bool override;
    // Add header labels
    auto        GetColLabelValue(int col) -> wxString override;

    [[nodiscard]]
    static auto GetColumnSizes(const wxGrid& grid) -> wxGridSizesInfo;
};

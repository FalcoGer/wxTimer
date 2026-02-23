#include "StopwatchTable.hpp"
#include <format>
#include <utility>
#include <wx/string.h>

auto StopwatchTable::GetNumberRows() -> int
{
    return static_cast<int>(m_stopwatchTimes.size());
}

auto StopwatchTable::GetNumberCols() -> int
{
    return 2;
}

//NOLINTNEXTLINE(bugprone-easily-swappable-parameters) // it can't be helped
auto StopwatchTable::GetValue(int row, int col) -> wxString
{
    const auto ROW = static_cast<std::size_t>(row);
    const auto COL = static_cast<std::size_t>(col);
    if (std::cmp_greater_equal(ROW, GetNumberRows()))
    {
        return "INVALID IDX";
    }
    if (ROW == 0 && COL == 1)
    {
        return "N/A";
    }

    const bool IS_LAST_ROW = (std::cmp_equal(ROW, GetNumberRows() - 1));
    if (IS_LAST_ROW)
    {
        // last row shows current time
        const auto NOW = std::chrono::steady_clock::now();
        if (COL == 0)
        {
            const auto FROM_START = std::chrono::duration_cast<std::chrono::milliseconds>(
              NOW - m_stopwatchTimes.front()
            );
            return std::format("{:%T}", FROM_START);
        }
        const auto DELTA_TO_LAST = std::chrono::duration_cast<std::chrono::milliseconds>(NOW - m_stopwatchTimes.back());
        return std::format("{:%T}", DELTA_TO_LAST);
    }

    // not in the last row.
    const auto TIME_TO_DISPLAY = m_stopwatchTimes.at(ROW + 1);
    if (COL == 0)
    {
        // time since start
        return std::format("{:%T}", TIME_TO_DISPLAY - m_stopwatchTimes.front());
    }
    // timce since last
    return std::format("{:%T}", TIME_TO_DISPLAY - m_stopwatchTimes.at(ROW));
}

//NOLINTNEXTLINE(bugprone-easily-swappable-parameters) // it can't be helped
void StopwatchTable::SetValue([[maybe_unused]] int row, [[maybe_unused]] int col, [[maybe_unused]] const wxString& value)
{
    // empty
}

// NOLINTNEXTLINE(google-default-arguments) // It can't be helped. Not my interface.
auto StopwatchTable::AppendRows(std::size_t numRows) -> bool
{
    const TimePoint NOW {std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now())};
    for (std::size_t i = 0; i < numRows; ++i)
    {
        m_stopwatchTimes.push_back(NOW);
    }
    wxGridTableMessage msg {this, wxGRIDTABLE_NOTIFY_ROWS_APPENDED, static_cast<int>(numRows)};
    GetView()->ProcessTableMessage(msg);
    return true;
}

// NOLINTNEXTLINE(google-default-arguments) // It can't be helped. Not my interface.
auto StopwatchTable::DeleteRows(std::size_t pos, std::size_t numRows) -> bool
{
    m_stopwatchTimes.erase(
      m_stopwatchTimes.begin() + static_cast<std::ptrdiff_t>(pos),
      m_stopwatchTimes.begin() + static_cast<std::ptrdiff_t>(pos + numRows)
    );
    wxGridTableMessage msg {this, wxGRIDTABLE_NOTIFY_ROWS_DELETED, static_cast<int>(pos), static_cast<int>(numRows)};
    GetView()->ProcessTableMessage(msg);
    return true;
}
auto StopwatchTable::GetColLabelValue(int col) -> wxString
{
    switch (col)
    {
        case 0:  return "Time";
        case 1:  return "Delta";
        default: return "INVALID";
    }
}
[[nodiscard]]
auto StopwatchTable::GetColumnSizes(const wxGrid& grid) -> wxGridSizesInfo
{
    const auto DEFAULT_SIZE    = 20;

    const auto WIDTH           = grid.GetSize().GetWidth();
    const auto COL_LABEL_WIDTH = grid.GetRowLabelSize();
    const auto SCOLL_BAR_WIDTH = wxSystemSettings::GetMetric(wxSYS_VSCROLL_X, &grid);
    const auto COL_WIDTH       = std::max((WIDTH - SCOLL_BAR_WIDTH - COL_LABEL_WIDTH) / 2, DEFAULT_SIZE);

    return wxGridSizesInfo(DEFAULT_SIZE, wxArrayInt({COL_WIDTH, COL_WIDTH}));
}

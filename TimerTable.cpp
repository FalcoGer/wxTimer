#include "TimerTable.hpp"
#include <algorithm>
#include <format>
#include <tuple>
#include <utility>
#include <wx/generic/grid.h>
#include <wx/generic/gridctrl.h>
#include <wx/generic/grideditors.h>
void TimerTable::sortTimers()
{
    std::ranges::sort(
      m_timers,
      [](const CountdownTimer& lhs, const CountdownTimer& rhs) -> bool
      {
          return std::forward_as_tuple(!lhs.isStarted(), lhs.getTime(), lhs.getName())
                 < std::forward_as_tuple(!rhs.isStarted(), rhs.getTime(), rhs.getName());
      }
    );

    wxGridTableMessage msg(this, wxGRIDTABLE_REQUEST_VIEW_GET_VALUES);
    GetView()->ProcessTableMessage(msg);
}
TimerTable::TimerTable()
        : m_leftSysBgAttr(new wxGridCellAttr()),
          m_leftRedBgAttr(new wxGridCellAttr()),
          m_rightSysBgAttr(new wxGridCellAttr()),
          m_rightRedBgAttr(new wxGridCellAttr()),
          m_checkboxAttr(new wxGridCellAttr())
{
    const wxColour DEFAULT = wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND);
    const wxColour RED     = wxColour(255, 0, 0);

    m_leftSysBgAttr->SetBackgroundColour(DEFAULT);
    m_leftRedBgAttr->SetBackgroundColour(RED);
    m_rightSysBgAttr->SetBackgroundColour(DEFAULT);
    m_rightRedBgAttr->SetBackgroundColour(RED);

    m_leftSysBgAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
    m_leftRedBgAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
    m_rightSysBgAttr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTER);
    m_rightRedBgAttr->SetAlignment(wxALIGN_RIGHT, wxALIGN_CENTER);

    // hack, but it works because we only use right attributes for the time field
    m_rightSysBgAttr->SetReadOnly();
    m_rightRedBgAttr->SetReadOnly();

    m_checkboxAttr->SetAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory) // wx receiver takes ownership.
    m_checkboxAttr->SetRenderer(new wxGridCellBoolRenderer());
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory) // wx receiver takes ownership.
    m_checkboxAttr->SetEditor(new wxGridCellBoolEditor());
}
TimerTable::~TimerTable()
{
    for (auto* const ptr_attr : {m_leftSysBgAttr, m_leftRedBgAttr, m_rightSysBgAttr, m_rightRedBgAttr, m_checkboxAttr})
    {
        ptr_attr->DecRef();
    }
}
auto TimerTable::GetNumberRows() -> int
{
    return static_cast<int>(m_timers.size());
}
auto TimerTable::GetNumberCols() -> int
{
    return 3;
}

//NOLINTNEXTLINE(bugprone-easily-swappable-parameters) // it can't be helped
auto TimerTable::GetValue(int row, int col) -> wxString
{
    const auto ROW = static_cast<std::size_t>(row);
    const auto COL = static_cast<std::size_t>(col);
    if (std::cmp_greater_equal(ROW, GetNumberRows()) || std::cmp_greater_equal(COL, GetNumberCols()))
    {
        return "INVALID IDX";
    }

    switch (COL)
    {
        case 0:  return m_timers.at(ROW).getName();
        case 1:  return std::format("{:%T}", m_timers.at(ROW).getTime());
        case 2:  return m_timers.at(ROW).isStarted() ? "1" : "";
        default: return "INVALID IDX";
    }
}
// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
void TimerTable::SetValue(int row, int col, const wxString& value)
{
    const auto ROW = static_cast<std::size_t>(row);
    switch (col)
    {
        case 0:
        {
            m_timers.at(ROW).setName(value.ToStdString());
            sortTimers();
            break;
        }
        case 1:
        {
            break;
        }
        case 2:
        {
            const bool VALUE = (value == "1");
            if (VALUE)
            {
                m_timers.at(ROW).startTimer();
            }
            else
            {
                m_timers.at(ROW).stopTimer();
            }
            sortTimers();
            break;
        }
        default: break;
    }
}
void TimerTable::setTimer(int row, CountdownTimer&& timer)
{
    m_timers.at(static_cast<std::size_t>(row)) = std::move(timer);
    sortTimers();
}
[[nodiscard]]
auto TimerTable::getTimerStarted(int row) const -> bool
{
    return m_timers.at(static_cast<std::size_t>(row)).isStarted();
}
void TimerTable::addTimer(CountdownTimer&& timer)
{
    m_timers.emplace_back(std::move(timer));
    sortTimers();
    wxGridTableMessage msg {this, wxGRIDTABLE_NOTIFY_ROWS_APPENDED, 1};
    GetView()->ProcessTableMessage(msg);
}

// NOLINTNEXTLINE(google-default-arguments) // It can't be helped. Not my interface.
auto TimerTable::DeleteRows(std::size_t pos, std::size_t numRows) -> bool
{
    m_timers.erase(
      m_timers.begin() + static_cast<std::ptrdiff_t>(pos), m_timers.begin() + static_cast<std::ptrdiff_t>(pos + numRows)
    );
    wxGridTableMessage msg {this, wxGRIDTABLE_NOTIFY_ROWS_DELETED, static_cast<int>(pos), static_cast<int>(numRows)};
    GetView()->ProcessTableMessage(msg);
    return true;
}
auto TimerTable::GetColLabelValue(int col) -> wxString
{
    switch (col)
    {
        case 0:  return "Name";
        case 1:  return "Time";
        case 2:  return "";
        default: return "INVALID";
    }
}
auto TimerTable::GetColumnSizes(const wxGrid& grid) -> wxGridSizesInfo
{
    const auto DEFAULT_SIZE    = 20;

    const auto WIDTH           = grid.GetSize().GetWidth();
    const auto COL_LABEL_WIDTH = grid.GetRowLabelSize();
    const auto CB_COL_SIZE     = 30;

    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast) // Safe because isn't changed, and also original grid is not const.
    wxClientDC dc {const_cast<wxGrid*>(&grid)};
    dc.SetFont(grid.GetDefaultCellFont());
    const auto TIME_COL_SIZE   = dc.GetTextExtent("-00:00:00").GetWidth() + 10;

    const auto SCOLL_BAR_WIDTH = wxSystemSettings::GetMetric(wxSYS_VSCROLL_X, &grid);
    const auto NAME_COL_SIZE =
      std::max(WIDTH - COL_LABEL_WIDTH - TIME_COL_SIZE - CB_COL_SIZE - SCOLL_BAR_WIDTH, DEFAULT_SIZE);

    return wxGridSizesInfo(DEFAULT_SIZE, wxArrayInt({NAME_COL_SIZE, TIME_COL_SIZE, CB_COL_SIZE}));
}

auto TimerTable::GetAttr(int row, int col, wxGridCellAttr::wxAttrKind kind) -> wxGridCellAttr*
{
    if (row < 0 || row >= GetNumberRows())
    {
        return wxGridTableBase::GetAttr(row, col, kind);
    }

    const bool            TIMER_NOTIFIED = m_timers.at(static_cast<std::size_t>(row)).isNotified();
    wxGridCellAttr* const ptr_attr       = [this, TIMER_NOTIFIED, col]() -> wxGridCellAttr*
    {
        const int64_t NOW =
          std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch()
          )
            .count();
        const int64_t HALF_SECOND = 500;
        const bool    IS_RED      = TIMER_NOTIFIED && (NOW / HALF_SECOND) % 2 == 0;
        switch (col)
        {
            case 0:  return IS_RED ? m_leftRedBgAttr : m_leftSysBgAttr;
            case 1:  return IS_RED ? m_rightRedBgAttr : m_rightSysBgAttr;
            case 2:  return m_checkboxAttr;
            default: return nullptr;
        }
    }();

    if (ptr_attr == nullptr)
    {
        return wxGridTableBase::GetAttr(row, col, kind);
    }

    ptr_attr->IncRef();
    return ptr_attr;
}

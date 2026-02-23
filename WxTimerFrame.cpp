#include "DialogAddEditTimer.hpp"
#include "WxTimerFrame.hpp"
#include "resources/stop.png.h"
#include <algorithm>
#include <chrono>
#include <ranges>
#include <wx/event.h>
#include <wx/font.h>
#include <wx/generic/grid.h>
#include <wx/gtk/colour.h>

// NOLINTNEXTLINE(readability-identifier-naming) // generated code
auto play_png_to_wx_bitmap() -> wxBitmap&;

WxTimerFrame::WxTimerFrame(wxWindow* ptr_parent)
        : WxTimerBase(ptr_parent), m_stopwatchTable(new StopwatchTable()), m_timerTable(new TimerTable())
{
    m_gridStopwatch->SetTable(m_stopwatchTable, true, wxGrid::wxGridSelectNone);
    m_gridStopwatch->Bind(
      wxEVT_SIZE,
      [this](wxSizeEvent& event)
      {
          event.Skip();    // allow internals to resize the grid and all that

          const int WIDTH = m_gridStopwatch->GetTextExtent("WWW").GetWidth();
          m_gridStopwatch->SetRowLabelSize(WIDTH);
          m_gridStopwatch->SetColSizes(StopwatchTable::GetColumnSizes(*m_gridStopwatch));
       }
    );

    m_gridTimer->SetTable(m_timerTable, true, wxGrid::wxGridSelectNone);
    m_gridTimer->Bind(
      wxEVT_SIZE,
      [this](wxSizeEvent& event)
      {
          event.Skip();    // allow internals to resize the grid and all that

          const int WIDTH = m_gridTimer->GetTextExtent("WWW").GetWidth();
          m_gridTimer->SetRowLabelSize(WIDTH);
          m_gridTimer->SetColSizes(TimerTable::GetColumnSizes(*m_gridTimer));
       }
    );

    // resize the grids after the window actually exists
    CallAfter(
      [this]()
      {
          Layout();
          m_gridStopwatch->SetColSizes(StopwatchTable::GetColumnSizes(*m_gridStopwatch));
          m_gridTimer->SetColSizes(TimerTable::GetColumnSizes(*m_gridTimer));

          m_gridStopwatch->ForceRefresh();
          m_gridTimer->ForceRefresh();
      }
    );
}

void WxTimerFrame::onTimerElapsed([[maybe_unused]] wxTimerEvent& event)
{
    switch (m_notebookMain->GetSelection())
    {
        case 0:
        {
            if (m_stopwatchState == EStopwatchState::RUNNING)
            {
                m_gridStopwatch->Refresh();
            }
            break;
        }
        case 1:
        {
            // is checking slower than just redrawing every time?
            if (std::ranges::any_of(m_timerTable->getTimers(), [](const Timer& timer) { return timer.isStarted(); }))
            {
                if (std::ranges::any_of(m_timerTable->getTimers(), [](const Timer& timer) { return timer.hasElapsed(); }))
                {
                    m_timerButtonCancel->Enable();

                    for (const auto& [idx, timer] : m_timerTable->getTimers() | std::views::enumerate)
                    {
                        if (timer.hasElapsed())
                        {
                            timer.audioPlay();
                        }
                        else
                        {
                            const wxColour COLOR = wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND);
                        }
                    }
                }
                m_gridTimer->Refresh();
            }
            else
            {
                m_timerButtonCancel->Enable(false);
            }
            break;
        }
        default:
        {
            break;
        }
    }
}
void WxTimerFrame::onClickStopwatchStartLap([[maybe_unused]] wxCommandEvent& event)
{
    m_gridStopwatch->AppendRows();

    // scroll to bottom
    m_gridStopwatch->ScrollLines(m_gridStopwatch->GetNumberRows() - 1);
    if (m_stopwatchState == EStopwatchState::STOPPED)
    {
        m_buttonStopwatchStartLap->SetLabel("Lap");
        m_stopwatchState = EStopwatchState::RUNNING;
    }
}
void WxTimerFrame::onClickStopwatchReset([[maybe_unused]] wxCommandEvent& event)
{
    m_stopwatchState = EStopwatchState::STOPPED;
    m_buttonStopwatchStartLap->SetLabel("Start");
    m_gridStopwatch->DeleteRows(0, m_gridStopwatch->GetNumberRows());
}
void WxTimerFrame::onAddTimerClick([[maybe_unused]] wxCommandEvent& event)
{
    const auto         DEFAULT_TIME = std::chrono::minutes(10);
    DialogAddEditTimer dialog(this, Timer {this, "New Timer", DEFAULT_TIME, std::filesystem::path(), true});

    if (dialog.ShowModal() == wxID_OK)
    {
        m_timerTable->addTimer(dialog.getTimer());
        m_gridTimer->Refresh();
    }
}
void WxTimerFrame::onEditTimerClick([[maybe_unused]] wxCommandEvent& event)
{
    const int ROW = m_gridTimer->GetGridCursorRow();
    if (ROW >= 0 && ROW < m_timerTable->GetNumberRows())
    {
        DialogAddEditTimer dialog(this, m_timerTable->getTimerCopy(ROW));
        if (dialog.ShowModal() == wxID_OK)
        {
            auto timer = dialog.getTimer();
            timer.stopTimer();
            m_timerTable->setTimer(ROW, std::move(timer));
            wxGridEvent evt{wxID_ANY, wxEVT_GRID_SELECT_CELL, m_gridTimer, ROW, m_gridTimer->GetGridCursorCol()};
            onTimerGridSelectionChanged(evt);
            m_gridTimer->Refresh();
        }
    }
}
void WxTimerFrame::onDeleteTimerClick([[maybe_unused]] wxCommandEvent& event)
{
    const int ROW = m_gridTimer->GetGridCursorRow();
    if (ROW >= 0 && ROW < m_timerTable->GetNumberRows())
    {
        m_timerTable->DeleteRows(static_cast<std::size_t>(ROW));
        wxGridEvent evt{wxID_ANY, wxEVT_GRID_SELECT_CELL, m_gridTimer, ROW, m_gridTimer->GetGridCursorCol()};
        onTimerGridSelectionChanged(evt);
        m_gridTimer->Refresh();
    }
}
void WxTimerFrame::onStartStopTimerClick([[maybe_unused]] wxCommandEvent& event)
{
    const int ROW = m_gridTimer->GetGridCursorRow();
    if (ROW >= 0 && ROW < m_timerTable->GetNumberRows())
    {
        const bool STARTED = m_timerTable->getTimerStarted(ROW);
        m_timerTable->SetValue(ROW, 2, STARTED ? "" : "1");
        const wxColour COLOR = wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND);
        m_gridTimer->SetCellBackgroundColour(ROW, 0, COLOR);
        m_gridTimer->SetCellBackgroundColour(ROW, 1, COLOR);
        wxGridEvent evt{wxID_ANY, wxEVT_GRID_SELECT_CELL, m_gridTimer, ROW, m_gridTimer->GetGridCursorCol()};
        onTimerGridSelectionChanged(evt);
        m_gridTimer->Refresh();
    }
}
void WxTimerFrame::onCancelTimerClick([[maybe_unused]] wxCommandEvent& event)
{
    // for every elapsed timer, stop the timer
    std::vector<int> elapsedTimers;
    for (const auto& [idx, timer] : m_timerTable->getTimers() | std::views::enumerate)
    {
        if (timer.hasElapsed())
        {
            const wxColour COLOR = wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND);
            m_gridTimer->SetCellBackgroundColour(static_cast<int>(idx), 0, COLOR);
            m_gridTimer->SetCellBackgroundColour(static_cast<int>(idx), 1, COLOR);
            elapsedTimers.push_back(static_cast<int>(idx));
        }
    }
    for (const auto ROW : std::views::reverse(elapsedTimers))
    {
        m_timerTable->SetValue(ROW, 2, "");
    }
    wxGridEvent evt{wxID_ANY, wxEVT_GRID_SELECT_CELL, m_gridTimer, m_gridTimer->GetGridCursorRow(), m_gridTimer->GetGridCursorCol()};
    onTimerGridSelectionChanged(evt);
    m_gridTimer->Refresh();
}
void WxTimerFrame::onTimerGridSelectionChanged(wxGridEvent& event)
{
    if (event.GetRow() < m_timerTable->GetNumberRows())
    {
        m_timerButtonEdit->Enable(true);
        m_timerButtonDelete->Enable(true);
        const auto STARTED = m_timerTable->getTimerStarted(event.GetRow());
        m_timerButtonStartStop->Enable(true);
        m_timerButtonStartStop->SetLabel(STARTED ? "Stop" : "Start");
        m_timerButtonStartStop->SetToolTip(STARTED ? "Stop timer" : "Start timer");
        m_timerButtonStartStop->SetBitmap(STARTED ? stop_png_to_wx_bitmap() : play_png_to_wx_bitmap());
    }
    else
    {
        m_timerButtonEdit->Enable(false);
        m_timerButtonDelete->Enable(false);
        m_timerButtonStartStop->SetLabel("Start");
        m_timerButtonStartStop->SetToolTip("Start timer");
        m_timerButtonStartStop->SetBitmap(play_png_to_wx_bitmap());
        m_timerButtonStartStop->Enable(false);
    }
}

void WxTimerFrame::onTimerGridCellChange(wxGridEvent& event)
{
    const auto     ROW   = event.GetRow();
    const wxColour COLOR = wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND);
    m_gridTimer->SetCellBackgroundColour(static_cast<int>(ROW), 0, COLOR);
    m_gridTimer->SetCellBackgroundColour(static_cast<int>(ROW), 1, COLOR);

    const bool STARTED = m_timerTable->getTimerStarted(ROW);
    m_timerButtonStartStop->SetToolTip(STARTED ? "Stop timer" : "Start timer");
    m_timerButtonStartStop->SetBitmap(STARTED ? stop_png_to_wx_bitmap() : play_png_to_wx_bitmap());

    m_gridTimer->Refresh();
}

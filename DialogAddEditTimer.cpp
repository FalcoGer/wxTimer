#include "DialogAddEditTimer.hpp"
#include <chrono>

DialogAddEditTimer::DialogAddEditTimer(wxWindow* const ptr_parent, CountdownTimer timer)
        : DialogAddEditTimerBase(ptr_parent), m_timer(std::move(timer))
{
    m_textCtrlTimerName->SetValue(m_timer.getName());
    const std::chrono::duration<double> TIME               = m_timer.getDuration();

    constexpr int                       SECONDS_PER_HOUR   = 3'600;
    constexpr int                       SECONDS_PER_MINUTE = 60;

    const int                           HOUR = std::min(static_cast<int>(TIME.count()) / SECONDS_PER_HOUR, 23);
    const int MINUTE                         = (static_cast<int>(TIME.count()) % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
    const int SECOND                         = static_cast<int>(TIME.count()) % SECONDS_PER_MINUTE;

    m_timePicker->SetTime(HOUR, MINUTE, SECOND);
    m_observerCreationPanel->setObserver(m_timer.getObserver()->clone());
    Bind(wxEVT_PANEL_UPDATED, &DialogAddEditTimer::onObserverUpdated, this);
}
[[nodiscard]]
auto DialogAddEditTimer::extractTimer() -> CountdownTimer&&
{
    return std::move(m_timer);
}

void DialogAddEditTimer::onNameChange(wxCommandEvent& event)
{
    m_timer.setName(event.GetString().ToStdString());
}
void DialogAddEditTimer::onTimeChange(wxDateEvent& event)
{
    const auto TIME = std::chrono::hours(event.GetDate().GetHour())
                      + std::chrono::minutes(event.GetDate().GetMinute())
                      + std::chrono::seconds(event.GetDate().GetSecond());
    m_timer.setDuration(TIME);
}
void DialogAddEditTimer::onObserverUpdated([[maybe_unused]] wxCommandEvent& event)
{
    m_timer.setObserver(m_observerCreationPanel->getObserver().clone());
    m_sdbSizerOK->Enable(m_observerCreationPanel->isValid());
}

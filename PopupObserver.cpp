#include "PopupObserver.hpp"
#include "TimerBase.hpp"
#include <chrono>
#include <wx/msgdlg.h>
#include <wx/string.h>

void PopupObserver::notify(TimerBase& timer)
{
    if (!m_triggered)
    {
        m_triggered = true;
        wxMessageBox(
        std::format(
            "Timer '{}' has elapsed at {:%Y-%m-%d %H:%M:%S}",
            timer.getName(),
            std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now())
        ),
        "Timer"
        );
    }
}
void PopupObserver::reset([[maybe_unused]] TimerBase& timer)
{
    m_triggered = false;
}
auto PopupObserver::isNotified() const -> bool
{
    return m_triggered;
}
auto PopupObserver::clone() const -> std::unique_ptr<IObserver>
{
    return std::make_unique<PopupObserver>(*this);
}

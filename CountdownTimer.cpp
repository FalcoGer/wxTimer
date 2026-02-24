#include "CountdownTimer.hpp"
#include <utility>

CountdownTimer::CountdownTimer(
  std::string name, std::chrono::duration<double> duration, std::unique_ptr<IObserver> observer
) : TimerBase {std::move(name), std::move(observer)}, m_duration {duration}
{
    // empty
}

[[nodiscard]]
auto CountdownTimer::getStart() const
  -> std::optional<std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds>>
{
    return m_start;
}
[[nodiscard]]
auto CountdownTimer::getDuration() const -> std::chrono::duration<double>
{
    return m_duration;
}
void CountdownTimer::setDuration(std::chrono::duration<double> duration)
{
    m_duration = duration;
}

void CountdownTimer::startTimer()
{
    m_start = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now());
    reset();
}

void CountdownTimer::stopTimer()
{
    m_start = std::nullopt;
    reset();
}
[[nodiscard]]
auto CountdownTimer::hasElapsed() const -> bool
{
    return isStarted() && getTime() <= std::chrono::duration<double>::zero();
}


[[nodiscard]]
auto CountdownTimer::getTime() const -> std::chrono::duration<double>
{
    if (!isStarted())
    {
        return m_duration;
    }

    const auto                          NOW       = std::chrono::steady_clock::now();
    const std::chrono::duration<double> TIME_LEFT = m_start.value()
                                                    + m_duration
                                                    - NOW;    // may be negative if time has passed
    return TIME_LEFT;
}

[[nodiscard]]
auto CountdownTimer::isStarted() const -> bool
{
    return m_start.has_value();
}

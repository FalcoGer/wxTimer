#pragma once

#include "TimerBase.hpp"
#include <chrono>
#include <memory>
#include <optional>
#include <string>

class CountdownTimer : public TimerBase
{
  private:
    std::optional<std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds>> m_start;
    std::chrono::duration<double>                                                                m_duration {};

  public:
    CountdownTimer(std::string name, std::chrono::duration<double> duration, std::unique_ptr<IObserver> observer);

    CountdownTimer() = delete;
    CountdownTimer(const CountdownTimer&) = default;
    auto operator= (const CountdownTimer&) -> CountdownTimer& = default;
    CountdownTimer(CountdownTimer&&) = default;
    auto operator= (CountdownTimer&&) -> CountdownTimer& = default;
    ~CountdownTimer() override = default;

    [[nodiscard]]
    auto getStart() const
      -> std::optional<std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds>>;

    [[nodiscard]]
    auto getDuration() const -> std::chrono::duration<double>;

    void setDuration(std::chrono::duration<double> duration);

    [[nodiscard]]
    auto isStarted() const -> bool override;

    void startTimer() override;

    void stopTimer() override;

    [[nodiscard]]
    auto hasElapsed() const -> bool override;

    [[nodiscard]]
    auto getTime() const -> std::chrono::duration<double> override;
};

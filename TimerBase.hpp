#pragma once

#include "IObserver.hpp"
#include <chrono>
#include <memory>
#include <string>
#include <string_view>

class TimerBase
{
  private:
    std::string                m_name;
    std::unique_ptr<IObserver> m_observer;

  public:
    TimerBase(std::string name, std::unique_ptr<IObserver> observer);
    TimerBase(const TimerBase&);
    auto operator= (const TimerBase&) -> TimerBase&;
    TimerBase(TimerBase&&) = default;
    auto operator= (TimerBase&&) noexcept -> TimerBase& = default;
    virtual ~TimerBase() = default;

    [[nodiscard]]
    auto getName() const -> const std::string&;
    void setName(std::string_view name);

    [[nodiscard]]
    virtual auto isStarted() const -> bool = 0;
    virtual void startTimer()              = 0;
    virtual void stopTimer()               = 0;
    [[nodiscard]]
    virtual auto hasElapsed() const -> bool = 0;
    [[nodiscard]]
    virtual auto getTime() const -> std::chrono::duration<double> = 0;

    void         update();
    void         reset();
    [[nodiscard]]
    auto isNotified() const -> bool;
    void setObserver(std::unique_ptr<IObserver> observer);
    [[nodiscard]]
    auto getObserver() const -> const std::unique_ptr<IObserver>&;
};

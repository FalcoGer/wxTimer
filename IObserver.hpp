#pragma once

#include <memory>
class TimerBase;

class IObserver
{
  public:
    virtual void notify(TimerBase& timer) = 0;
    virtual void reset(TimerBase& timer)  = 0;
    [[nodiscard]]
    virtual auto isNotified() const -> bool = 0;
    virtual ~IObserver()                    = default;
    [[nodiscard]]
    virtual auto clone() const -> std::unique_ptr<IObserver> = 0;
};

#pragma once

#include <memory>
class IObserver
{
  public:
    virtual void notify() = 0;
    virtual void reset()  = 0;
    [[nodiscard]]
    virtual auto isNotified() const -> bool = 0;
    virtual ~IObserver()                    = default;
    [[nodiscard]]
    virtual auto clone() const -> std::unique_ptr<IObserver> = 0;
};

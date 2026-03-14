#pragma once

#include "IObserver.hpp"

class PopupObserver : public IObserver
{
  private:

  public:
    void notify(TimerBase& timer) override;
    void reset(TimerBase& timer) override;
    [[nodiscard]]
    auto isNotified() const -> bool override;
    [[nodiscard]]
    auto clone() const -> std::unique_ptr<IObserver> override;
};

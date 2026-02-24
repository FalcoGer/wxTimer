#pragma once

#include "IObserver.hpp"
class NothingObserver : public IObserver
{
  private:
    bool m_isNotified;
  public:
    void notify() override;
    void reset() override;
    [[nodiscard]]
    auto isNotified() const -> bool override;
    [[nodiscard]]
    auto clone() const -> std::unique_ptr<IObserver> override;
};

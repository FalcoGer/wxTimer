#include "NothingObserver.hpp"

void NothingObserver::notify([[maybe_unused]] TimerBase& timer)
{
    m_isNotified = true;
}
void NothingObserver::reset([[maybe_unused]] TimerBase& timer)
{
    m_isNotified = false;
}
auto NothingObserver::isNotified() const -> bool
{
    return m_isNotified;
}
auto NothingObserver::clone() const -> std::unique_ptr<IObserver>
{
    return std::make_unique<NothingObserver>(*this);
}

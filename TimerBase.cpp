#include "TimerBase.hpp"
#include <stdexcept>
#include <utility>

TimerBase::TimerBase(std::string name, std::unique_ptr<IObserver> observer)
        : m_name {std::move(name)}, m_observer {std::move(observer)}
{
    if (!m_observer)
    {
        throw std::invalid_argument("Observer cannot be null");
    }
}
TimerBase::TimerBase(const TimerBase& other) : m_name {other.m_name}, m_observer {other.m_observer->clone()}
{
    // empty
}
auto TimerBase::operator= (const TimerBase& other) -> TimerBase&
{
    if (this == &other)
    {
        return *this;
    }
    m_name     = other.m_name;
    m_observer = other.m_observer->clone();
    return *this;
}
void TimerBase::setName(std::string_view name)
{
    m_name = name;
}
void TimerBase::update()
{
    if (hasElapsed() && !isNotified())
    {
        m_observer->notify();
    }
}
void TimerBase::reset()
{
    (*m_observer).reset();
}
[[nodiscard]]
auto TimerBase::isNotified() const -> bool
{
    return m_observer->isNotified();
}
void TimerBase::setObserver(std::unique_ptr<IObserver> observer)
{
    if (!observer)
    {
        throw std::invalid_argument("Observer cannot be null");
    }
    m_observer = std::move(observer);
}

auto TimerBase::getObserver() const -> const std::unique_ptr<IObserver>&
{
    return m_observer;
}

[[nodiscard]]
auto TimerBase::getName() const -> const std::string&
{
    return m_name;
}

#include "Timer.hpp"
#include <utility>
#include <wx/mediactrl.h>

Timer::Timer(wxWindow* ptr_parent, std::string name, std::chrono::duration<double> duration, std::filesystem::path soundFile, bool repeat)
        : m_name{std::move(name)},
          m_duration{duration},
          m_soundFile{std::move(soundFile)},
          m_loopAudio{repeat},
          m_sound {new wxMediaCtrl(ptr_parent, wxID_ANY)}
{
    m_sound->Load(m_soundFile.string());
    m_sound->Bind(wxEVT_MEDIA_FINISHED, m_repeatEvent);
}

Timer::Timer(Timer&& other) noexcept
  : m_name{std::move(other.m_name)}, m_start{other.m_start}, m_duration{other.m_duration}, m_soundFile{std::move(other.m_soundFile)}, m_loopAudio{other.m_loopAudio}, m_sound{std::exchange(other.m_sound, nullptr)}
{
    m_sound->Unbind(wxEVT_MEDIA_FINISHED, other.m_repeatEvent);
    m_sound->Bind(wxEVT_MEDIA_FINISHED, m_repeatEvent);
}

Timer::~Timer()
{
    if (m_sound != nullptr)
    {
        m_sound->Destroy();
    }
}

Timer::Timer(const Timer& other) : Timer(other.m_sound->GetParent(), other.m_name, other.m_duration, other.m_soundFile, other.m_loopAudio)
{
    m_start = other.m_start;
}

auto Timer::operator= (const Timer& rhs) -> Timer&
{
    if (this == &rhs)
    {
        return *this;
    }
    m_name = rhs.m_name;
    m_start = rhs.m_start;
    m_duration = rhs.m_duration;
    m_soundFile = rhs.m_soundFile;
    m_loopAudio    = rhs.m_loopAudio;
    m_sound->Load(m_soundFile.string());
    return *this;
}

auto Timer::operator=(Timer&& rhs)  noexcept -> Timer&
{
    if (this == &rhs)
    {
        return *this;
    }
    m_name = std::move(rhs.m_name);
    m_start = rhs.m_start;
    m_duration = rhs.m_duration;
    m_soundFile = std::move(rhs.m_soundFile);
    m_loopAudio    = rhs.m_loopAudio;
    if (m_sound != nullptr)
    {
        m_sound->Destroy();
    }
    rhs.m_sound->Unbind(wxEVT_MEDIA_FINISHED, rhs.m_repeatEvent);
    m_sound = std::exchange(rhs.m_sound, nullptr);
    m_sound->Bind(wxEVT_MEDIA_FINISHED, m_repeatEvent);
    return *this;
}

[[nodiscard]]
auto Timer::GetFileExtensionList()  -> const FileExtensionList&
{
    return FILE_EXTENSION_LIST;
}

[[nodiscard]]
auto Timer::getSoundFile() const -> const std::filesystem::path&
{
    return m_soundFile;
}

[[nodiscard("Check if file valid with return value")]]
auto Timer::setSoundFile(std::filesystem::path soundFile) -> std::expected<void, std::string>
{
    if (soundFile.empty())
    {
        return std::unexpected<std::string>("File path is empty");
    }

    if (!std::filesystem::exists(soundFile))
    {
        return std::unexpected<std::string>("File path does not exist");
    }

    if (!std::filesystem::is_regular_file(soundFile) && !std::filesystem::is_symlink(soundFile))
    {
        return std::unexpected<std::string>("File path is not a regular file or a symlink");
    }

    const std::string EXTENSION = soundFile.extension().string();
    if (std::ranges::find(FILE_EXTENSION_LIST, EXTENSION.starts_with('.') ? EXTENSION.substr(1) : EXTENSION) == FILE_EXTENSION_LIST.end())
    {
        return std::unexpected<std::string>(std::format("File extension '{}' is not allowed", EXTENSION));
    }
    m_soundFile = std::move(soundFile);
    m_sound->Load(m_soundFile.string());
    return {};
}

[[nodiscard]]
auto Timer::getLoopAudio() const -> bool
{
    return m_loopAudio;
}
void Timer::setLoopAudio(bool repeat)
{
    m_loopAudio = repeat;
}
[[nodiscard]]
auto Timer::getStart() const
  -> std::optional<std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds>>
{
    return m_start;
}
[[nodiscard]]
auto Timer::getDuration() const -> std::chrono::duration<double>
{
    return m_duration;
}
void Timer::setDuration(std::chrono::duration<double> duration)
{
    m_duration = duration;
}

void Timer::startTimer()
{
    m_start = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now());
    audioStop();
}

void Timer::stopTimer()
{
    m_start = std::nullopt;
    audioStop();
}
[[nodiscard]]
auto Timer::hasElapsed() const -> bool
{
    return isStarted() && getTime() <= std::chrono::duration<double>::zero();
}
void Timer::audioPlay()
{
    if (!m_playbackStarted)
    {
        m_playbackStarted = true;
        m_sound->Play();
    }
}

void Timer::audioStop()
{
    m_sound->Stop();
    m_playbackStarted = false;
}

[[nodiscard]]
auto Timer::getTime() const -> std::chrono::duration<double>
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
auto Timer::isStarted() const -> bool
{
    return m_start.has_value();
}

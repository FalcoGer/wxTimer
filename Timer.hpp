#pragma once

#include "FileExtensionList.hpp"
#include <chrono>
#include <expected>
#include <filesystem>
#include <functional>
#include <optional>
#include <string>
#include <string_view>
#include <wx/mediactrl.h>

class Timer
{
  private:
    std::string                                                                                  m_name;
    std::optional<std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds>> m_start;
    std::chrono::duration<double>                                                                m_duration {};
    std::filesystem::path                                                                        m_soundFile;
    bool                                                                                         m_loopAudio;
    // NOLINTNEXTLINE(bugprone-throwing-static-initialization) // No idea how to fix.
    static inline const FileExtensionList FILE_EXTENSION_LIST {"wav", "ogg", "mp3"};

    wxMediaCtrl*                          m_sound;
    bool                                  m_playbackStarted = false;
    std::function<void(wxMediaEvent&)>    m_repeatEvent     = [this](wxMediaEvent&)
    {
        if (m_loopAudio)
        {
            m_sound->Stop();
            m_sound->Play();
        }
    };

  public:
    Timer(wxWindow* ptr_parent, std::string name, std::chrono::duration<double> duration, std::filesystem::path soundFile, bool repeat);

    Timer() = delete;
    Timer(const Timer& other);
    auto operator= (const Timer& rhs) -> Timer&;
    Timer(Timer&& other) noexcept;
    auto operator= (Timer&&) noexcept -> Timer&;
    ~Timer();

    [[nodiscard]]
    static auto GetFileExtensionList() -> const FileExtensionList&;

    [[nodiscard]]
    auto getName() const -> const std::string&
    {
        return m_name;
    }

    void setName(std::string_view name) { m_name = name; }

    [[nodiscard]]
    auto getSoundFile() const -> const std::filesystem::path&;

    [[nodiscard("Check if file valid with return value")]]
    auto setSoundFile(std::filesystem::path soundFile) -> std::expected<void, std::string>;

    [[nodiscard]]
    auto getLoopAudio() const -> bool;

    void setLoopAudio(bool repeat);

    [[nodiscard]]
    auto getStart() const
      -> std::optional<std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds>>;

    [[nodiscard]]
    auto getDuration() const -> std::chrono::duration<double>;

    void setDuration(std::chrono::duration<double> duration);

    [[nodiscard]]
    auto isStarted() const -> bool;

    void startTimer();

    void stopTimer();

    [[nodiscard]]
    auto hasElapsed() const -> bool;

    [[nodiscard]]
    auto getTime() const -> std::chrono::duration<double>;

    void audioPlay();
    void audioStop();
};

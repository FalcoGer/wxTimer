#pragma once

#include "FileExtensionList.hpp"
#include "IObserver.hpp"
#include <expected>
#include <filesystem>
#include <functional>
#include <wx/mediactrl.h>

class AudioPlaybackObserver : public IObserver
{
  private:
    std::filesystem::path                 m_soundFile;
    bool                                  m_loopAudio;
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
    AudioPlaybackObserver(wxWindow* const ptr_parent, std::filesystem::path soundFile, const bool LOOP_AUDIO);
    AudioPlaybackObserver(const AudioPlaybackObserver& other);

    AudioPlaybackObserver(AudioPlaybackObserver&& other) noexcept;

    auto operator= (const AudioPlaybackObserver& rhs) -> AudioPlaybackObserver&;

    auto operator= (AudioPlaybackObserver&& rhs) noexcept -> AudioPlaybackObserver&;

    ~AudioPlaybackObserver() override;
    void notify(TimerBase& timer) override;

    void reset(TimerBase& timer) override;

    [[nodiscard]]
    static auto GetFileExtensionList() -> const FileExtensionList&;

    [[nodiscard]]
    auto isNotified() const -> bool override;

    [[nodiscard]]
    auto clone() const -> std::unique_ptr<IObserver> override;

    [[nodiscard]]
    auto getSoundFile() const -> const std::filesystem::path&;

    [[nodiscard("Check if file valid with return value")]]
    auto setSoundFile(std::filesystem::path soundFile) -> std::expected<void, std::string>;

    [[nodiscard]]
    auto getLoopAudio() const -> bool;

    void setLoopAudio(const bool LOOP_AUDIO);
};

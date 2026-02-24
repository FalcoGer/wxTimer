#include "AudioPlaybackObserver.hpp"

#include <utility>

AudioPlaybackObserver::AudioPlaybackObserver(wxWindow* const ptr_parent, std::filesystem::path soundFile, const bool LOOP_AUDIO)
        : m_soundFile {std::move(soundFile)}, m_loopAudio {LOOP_AUDIO}, m_sound(new wxMediaCtrl(ptr_parent, wxID_ANY))
{
    m_sound->Load(m_soundFile.string());
    m_sound->Bind(wxEVT_MEDIA_FINISHED, m_repeatEvent);
}

AudioPlaybackObserver::AudioPlaybackObserver(const AudioPlaybackObserver& other)
        : AudioPlaybackObserver(other.m_sound->GetParent(), other.m_soundFile, other.m_loopAudio)
{
    // empty
}

AudioPlaybackObserver::AudioPlaybackObserver(AudioPlaybackObserver&& other) noexcept
        : m_soundFile {std::move(other.m_soundFile)},
          m_loopAudio {other.m_loopAudio},
          m_sound {std::exchange(other.m_sound, nullptr)}
{
    m_sound->Unbind(wxEVT_MEDIA_FINISHED, other.m_repeatEvent);
    m_sound->Bind(wxEVT_MEDIA_FINISHED, m_repeatEvent);
}

auto AudioPlaybackObserver::operator= (const AudioPlaybackObserver& rhs) -> AudioPlaybackObserver&
{
    if (this == &rhs)
    {
        return *this;
    }
    setLoopAudio(rhs.m_loopAudio);
    m_soundFile = rhs.m_soundFile;
    m_sound->Load(m_soundFile.string());
    return *this;
}

auto AudioPlaybackObserver::operator= (AudioPlaybackObserver&& rhs) noexcept -> AudioPlaybackObserver&
{
    if (this == &rhs)
    {
        return *this;
    }
    m_soundFile = std::move(rhs.m_soundFile);
    m_loopAudio = rhs.m_loopAudio;
    if (m_sound != nullptr)
    {
        m_sound->Destroy();
    }
    m_sound = std::exchange(rhs.m_sound, nullptr);
    m_sound->Unbind(wxEVT_MEDIA_FINISHED, rhs.m_repeatEvent);

    m_sound->Bind(wxEVT_MEDIA_FINISHED, m_repeatEvent);
    return *this;
}

AudioPlaybackObserver::~AudioPlaybackObserver()
{
    if (m_sound != nullptr)
    {
        m_sound->Destroy();
    }
}

auto AudioPlaybackObserver::GetFileExtensionList() -> const FileExtensionList&
{
    return FILE_EXTENSION_LIST;
}

void AudioPlaybackObserver::notify()
{
    if (m_playbackStarted)
    {
        return;
    }
    m_sound->Stop();
    m_sound->Play();
    m_playbackStarted = true;
}

auto AudioPlaybackObserver::isNotified() const -> bool
{
    return m_playbackStarted;
}

auto AudioPlaybackObserver::getSoundFile() const -> const std::filesystem::path&
{
    return m_soundFile;
}

auto AudioPlaybackObserver::setSoundFile(std::filesystem::path soundFile) -> std::expected<void, std::string>
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
    if (
      std::ranges::find(FILE_EXTENSION_LIST, EXTENSION.starts_with('.') ? EXTENSION.substr(1) : EXTENSION)
      == FILE_EXTENSION_LIST.end()
    )
    {
        return std::unexpected<std::string>(std::format("File extension '{}' is not allowed", EXTENSION));
    }
    m_soundFile = std::move(soundFile);
    m_sound->Load(m_soundFile.string());
    return {};
}

auto AudioPlaybackObserver::getLoopAudio() const -> bool
{
    return m_loopAudio;
}

void AudioPlaybackObserver::setLoopAudio(const bool LOOP_AUDIO)
{
    m_loopAudio = LOOP_AUDIO;
}

auto AudioPlaybackObserver::clone() const -> std::unique_ptr<IObserver>
{
    return std::make_unique<AudioPlaybackObserver>(*this);
}

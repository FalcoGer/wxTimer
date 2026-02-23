#include "DialogAddEditTimer.hpp"
#include <chrono>

DialogAddEditTimer::DialogAddEditTimer(wxWindow* const ptr_parent, Timer timer)
        : DialogAddEditTimerBase(ptr_parent), m_timer(std::move(timer))
{
    m_textCtrlTimerName->SetValue(m_timer.getName());
    m_textCtrlSoundFilePath->SetValue(m_timer.getSoundFile().string());
    m_cbLoopAudio->SetValue(m_timer.getLoopAudio());
    const std::chrono::duration<double> TIME               = m_timer.getDuration();

    constexpr int                       SECONDS_PER_HOUR   = 3'600;
    constexpr int                       SECONDS_PER_MINUTE = 60;

    const int                           HOUR = std::min(static_cast<int>(TIME.count()) / SECONDS_PER_HOUR, 23);
    const int MINUTE                         = (static_cast<int>(TIME.count()) % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
    const int SECOND                         = static_cast<int>(TIME.count()) % SECONDS_PER_MINUTE;

    m_timePicker->SetTime(HOUR, MINUTE, SECOND);
}
[[nodiscard]]
auto DialogAddEditTimer::getTimer() const -> Timer
{
    return m_timer;
}
void DialogAddEditTimer::onNameChange(wxCommandEvent& event)
{
    m_timer.setName(event.GetString().ToStdString());
}
void DialogAddEditTimer::onTimeChange(wxDateEvent& event)
{
    const auto TIME = std::chrono::hours(event.GetDate().GetHour())
                      + std::chrono::minutes(event.GetDate().GetMinute())
                      + std::chrono::seconds(event.GetDate().GetSecond());
    m_timer.setDuration(TIME);
}
void DialogAddEditTimer::onFileChange(wxCommandEvent& event)
{
    const auto RESULT = m_timer.setSoundFile(event.GetString().ToStdString());
    if (RESULT.has_value())
    {
        m_sdbSizerOK->Enable(true);
        m_textCtrlSoundFilePath->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        m_textCtrlSoundFilePath->SetToolTip(wxEmptyString);
    }
    else
    {
        m_sdbSizerOK->Enable(false);
        m_textCtrlSoundFilePath->SetBackgroundColour(wxColour("tomato"));
        m_textCtrlSoundFilePath->SetToolTip(RESULT.error());
    }
}
void DialogAddEditTimer::onButtonOpenClick([[maybe_unused]] wxCommandEvent& event)
{
    wxFileDialog dialog(
      this,
      "Select Sound File",
      defaultDirectory,
      wxEmptyString,
      Timer::GetFileExtensionList().getWildcardForFileDialogue(true, true),
      wxDEFAULT_DIALOG_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dialog.ShowModal() == wxID_OK)
    {
        m_textCtrlSoundFilePath->SetValue(dialog.GetPath());
        defaultDirectory = dialog.GetDirectory().ToStdString();
    }
}
void DialogAddEditTimer::onCBLoopAudioChange(wxCommandEvent& event)
{
    m_timer.setLoopAudio(event.IsChecked());
}

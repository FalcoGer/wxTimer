#pragma once
#include <wx/wx.h>
#include <wx/filename.h>

#include <string>
#include <vector>


class MainFrame : public wxFrame
{
private:    // Consts
    const int DELTA_TIME = 100; // time between timer events (in ms)
    const std::string TIMER_FILE_NAME = "timers.txt";
    const std::string APP_NAME = "wxAlarm";
    const std::string DISPLAY_NAME = "wxAlarm";
private:    // private member variables
    wxFileName timerFileName;
private:    // private member functions
    void loadTimersFromFile();
    bool saveTimersToFile() const;
private:    // Contents
    wxTimer* timer = nullptr;
    wxListBox* timersList = nullptr;
    wxToolBar* toolBar = nullptr;
private:    // EventHandlers
    void OnTimer(wxTimerEvent& evt);
    void OnButtonClick(wxCommandEvent& evt);
private:    // enums
    enum class IDs : wxWindowID
    {
        MainWindow = 1000,
        Timer
    };
public:
    MainFrame(wxApp* app);
    virtual ~MainFrame();

};


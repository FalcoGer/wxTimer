#include "MainFrame.h"
#include <wx/stdpaths.h>

// TODO: remove iostream
#include <iostream>


void MainFrame::OnTimer(wxTimerEvent& evt)
{
    wxUnusedVar(evt);
    std::cout << "Timer Event! (TODO)" << std::endl;
}

void MainFrame::OnButtonClick(wxCommandEvent& evt)
{
    wxUnusedVar(evt);
    std::cout << "Button Event! (TODO)" << std::endl;
}

MainFrame::MainFrame(wxApp* app)
    : wxFrame(nullptr, static_cast<wxWindowID>(IDs::MainWindow), wxString(app->GetAppDisplayName()), wxPoint(0, 0), wxSize(600, 400))
{
    app->SetAppName(APP_NAME);
    app->SetAppDisplayName(DISPLAY_NAME);
    // get the cross plattform directory in which to store data for the user
    // windows: docmuments and settings/username/appdata/Application Data/appname/
    // unix: ~/.appname
    // mac: who cares
    std::string path = wxStandardPaths::Get().GetUserDataDir().ToStdString();
    timerFileName = wxFileName(path, TIMER_FILE_NAME);

    // create dir if it does not exist
    if (!timerFileName.DirExists())
    {
        std::cout << "Creating " << timerFileName.GetPath() << std::endl;
        if (!timerFileName.Mkdir())
        {
            Close();
        }
    }
    // create file if it does not exist
    wxFile timerFile;
    if (!timerFileName.FileExists())
    {
        std::cout << "Creating " << timerFileName.GetFullPath() << std::endl;
        timerFile.Open(timerFileName.GetFullPath(), wxFile::OpenMode::write);
        timerFile.Close();
    }
    loadTimersFromFile();

    // Setup wxElements
    // Timer
    timer = new wxTimer(this, static_cast<int>(IDs::Timer));
    Bind(
        wxEVT_TIMER,                    // evt type
        &MainFrame::OnTimer,            // callback
        this,                           // parent
        timer->GetId()                  // id
    );
    timer->Start(DELTA_TIME, wxTIMER_CONTINUOUS);
}

MainFrame::~MainFrame()
{
    if (timer->IsRunning())
    {
        timer->Stop();
    }
}

void MainFrame::loadTimersFromFile()
{
}

bool MainFrame::saveTimersToFile() const
{
    return false;
}

#include <wx/wx.h>
#include "MainFrame.h"

// application class
class Main : public wxApp
{
public:
	// function called at the application initialization
	virtual bool OnInit();
};


IMPLEMENT_APP(Main)

bool Main::OnInit()
{
	// create a new frame and set it as the top most application window
    MainFrame* mainFrame = new MainFrame(this);
	SetTopWindow(mainFrame);

	// show main frame
	mainFrame->Show();

	// enter the application's main loop
	return true;
}

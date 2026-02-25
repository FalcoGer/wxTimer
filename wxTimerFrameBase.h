///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-115-g11c2dec8)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/timer.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class WxTimerFrameBase
///////////////////////////////////////////////////////////////////////////////
class WxTimerFrameBase : public wxFrame
{
	private:

	protected:
		wxTimer m_timer;
		wxNotebook* m_notebookMain;
		wxPanel* m_panelStopwatch;
		wxGrid* m_gridStopwatch;
		wxButton* m_buttonStopwatchStartLap;
		wxButton* m_buttonStopwatchReset;
		wxPanel* m_panelTimer;
		wxBitmapButton* m_timerButtonAdd;
		wxBitmapButton* m_timerButtonEdit;
		wxBitmapButton* m_timerButtonDelete;
		wxBitmapButton* m_timerButtonStartStop;
		wxBitmapButton* m_timerButtonCancel;
		wxGrid* m_gridTimer;
		wxPanel* m_panelAlarm;

		// Virtual event handlers, override them in your derived class
		virtual void onTimerElapsed( wxTimerEvent& event ) = 0;
		virtual void onClickStopwatchStartLap( wxCommandEvent& event ) = 0;
		virtual void onClickStopwatchReset( wxCommandEvent& event ) = 0;
		virtual void onAddTimerClick( wxCommandEvent& event ) = 0;
		virtual void onEditTimerClick( wxCommandEvent& event ) = 0;
		virtual void onDeleteTimerClick( wxCommandEvent& event ) = 0;
		virtual void onStartStopTimerClick( wxCommandEvent& event ) = 0;
		virtual void onCancelTimerClick( wxCommandEvent& event ) = 0;
		virtual void onTimerGridCellChange( wxGridEvent& event ) = 0;
		virtual void onTimerGridSelectionChanged( wxGridEvent& event ) = 0;


	public:

		WxTimerFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Timer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 416,418 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~WxTimerFrameBase();

};


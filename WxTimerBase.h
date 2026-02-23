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
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/timectrl.h>
#include <wx/dateevt.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class WxTimerBase
///////////////////////////////////////////////////////////////////////////////
class WxTimerBase : public wxFrame
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

		WxTimerBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Timer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 416,418 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~WxTimerBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogAddEditTimerBase
///////////////////////////////////////////////////////////////////////////////
class DialogAddEditTimerBase : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrlTimerName;
		wxStaticText* m_staticText2;
		wxTimePickerCtrl* m_timePicker;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrlSoundFilePath;
		wxBitmapButton* m_bpButton7;
		wxCheckBox* m_cbLoopAudio;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;

		// Virtual event handlers, override them in your derived class
		virtual void onNameChange( wxCommandEvent& event ) = 0;
		virtual void onTimeChange( wxDateEvent& event ) = 0;
		virtual void onFileChange( wxCommandEvent& event ) = 0;
		virtual void onButtonOpenClick( wxCommandEvent& event ) = 0;
		virtual void onCBLoopAudioChange( wxCommandEvent& event ) = 0;


	public:

		DialogAddEditTimerBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Add/Edit Timer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~DialogAddEditTimerBase();

};


///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-115-g11c2dec8)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif

#include "WxTimerBase.h"

#include "resources/cancel.png.h"
#include "resources/edit.png.h"
#include "resources/list_remove.png.h"
#include "resources/newTimer.png.h"
#include "resources/play.png.h"

///////////////////////////////////////////////////////////////////////////

WxTimerBase::WxTimerBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_timer.SetOwner( this, m_timer.GetId() );
	m_timer.Start( 50 );

	wxBoxSizer* m_sizerMain;
	m_sizerMain = new wxBoxSizer( wxVERTICAL );

	m_notebookMain = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelStopwatch = new wxPanel( m_notebookMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_sizerStopwatch;
	m_sizerStopwatch = new wxBoxSizer( wxVERTICAL );

	m_gridStopwatch = new wxGrid( m_panelStopwatch, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALWAYS_SHOW_SB|wxVSCROLL );

	// Grid
	m_gridStopwatch->CreateGrid( 0, 2 );
	m_gridStopwatch->EnableEditing( false );
	m_gridStopwatch->EnableGridLines( true );
	m_gridStopwatch->EnableDragGridSize( false );
	m_gridStopwatch->SetMargins( 0, 0 );

	// Columns
	m_gridStopwatch->SetColSize( 0, 150 );
	m_gridStopwatch->SetColSize( 1, 150 );
	m_gridStopwatch->EnableDragColMove( false );
	m_gridStopwatch->EnableDragColSize( false );
	m_gridStopwatch->SetColLabelValue( 0, _("Time") );
	m_gridStopwatch->SetColLabelValue( 1, _("Delta") );
	m_gridStopwatch->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridStopwatch->EnableDragRowSize( false );
	m_gridStopwatch->SetRowLabelSize( wxGRID_AUTOSIZE );
	m_gridStopwatch->SetRowLabelAlignment( wxALIGN_RIGHT, wxALIGN_CENTER );

	// Label Appearance
	m_gridStopwatch->SetLabelFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	// Cell Defaults
	m_gridStopwatch->SetDefaultCellFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_gridStopwatch->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	m_sizerStopwatch->Add( m_gridStopwatch, 1, wxALIGN_LEFT|wxALIGN_TOP|wxALL|wxEXPAND, 5 );

	wxBoxSizer* m_sizerStopwatchButtons;
	m_sizerStopwatchButtons = new wxBoxSizer( wxHORIZONTAL );

	m_buttonStopwatchStartLap = new wxButton( m_panelStopwatch, wxID_ANY, _("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerStopwatchButtons->Add( m_buttonStopwatchStartLap, 0, wxALL, 5 );

	m_buttonStopwatchReset = new wxButton( m_panelStopwatch, wxID_ANY, _("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerStopwatchButtons->Add( m_buttonStopwatchReset, 0, wxALL, 5 );


	m_sizerStopwatch->Add( m_sizerStopwatchButtons, 0, wxEXPAND, 5 );


	m_panelStopwatch->SetSizer( m_sizerStopwatch );
	m_panelStopwatch->Layout();
	m_sizerStopwatch->Fit( m_panelStopwatch );
	m_notebookMain->AddPage( m_panelStopwatch, _("Stopwatch"), false );
	m_panelTimer = new wxPanel( m_notebookMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_sizerTimerMain;
	m_sizerTimerMain = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* m_sizer_TimerButtons;
	m_sizer_TimerButtons = new wxBoxSizer( wxHORIZONTAL );

	m_timerButtonAdd = new wxBitmapButton( m_panelTimer, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|0 );

	m_timerButtonAdd->SetBitmap( newTimer_png_to_wx_bitmap() );
	m_timerButtonAdd->SetToolTip( _("Add a new timer") );

	m_sizer_TimerButtons->Add( m_timerButtonAdd, 0, wxALL, 5 );

	m_timerButtonEdit = new wxBitmapButton( m_panelTimer, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|0 );

	m_timerButtonEdit->SetBitmap( edit_png_to_wx_bitmap() );
	m_timerButtonEdit->Enable( false );
	m_timerButtonEdit->SetToolTip( _("Edit the selected timer") );

	m_sizer_TimerButtons->Add( m_timerButtonEdit, 0, wxALL, 5 );

	m_timerButtonDelete = new wxBitmapButton( m_panelTimer, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|0 );

	m_timerButtonDelete->SetBitmap( list_remove_png_to_wx_bitmap() );
	m_timerButtonDelete->Enable( false );
	m_timerButtonDelete->SetToolTip( _("Remove the selected timer") );

	m_sizer_TimerButtons->Add( m_timerButtonDelete, 0, wxALL, 5 );


	m_sizer_TimerButtons->Add( 4, 0, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );

	m_timerButtonStartStop = new wxBitmapButton( m_panelTimer, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|0 );

	m_timerButtonStartStop->SetBitmap( play_png_to_wx_bitmap() );
	m_timerButtonStartStop->Enable( false );
	m_timerButtonStartStop->SetToolTip( _("Start timer") );

	m_sizer_TimerButtons->Add( m_timerButtonStartStop, 0, wxALL, 5 );

	m_timerButtonCancel = new wxBitmapButton( m_panelTimer, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|0 );

	m_timerButtonCancel->SetBitmap( cancel_png_to_wx_bitmap() );
	m_timerButtonCancel->Enable( false );
	m_timerButtonCancel->SetToolTip( _("Stop all alarms") );

	m_sizer_TimerButtons->Add( m_timerButtonCancel, 0, wxALL, 5 );


	m_sizerTimerMain->Add( m_sizer_TimerButtons, 0, wxEXPAND, 5 );

	m_gridTimer = new wxGrid( m_panelTimer, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALWAYS_SHOW_SB|wxVSCROLL );

	// Grid
	m_gridTimer->CreateGrid( 0, 3 );
	m_gridTimer->EnableEditing( true );
	m_gridTimer->EnableGridLines( true );
	m_gridTimer->EnableDragGridSize( false );
	m_gridTimer->SetMargins( 0, 0 );

	// Columns
	m_gridTimer->SetColSize( 0, 160 );
	m_gridTimer->SetColSize( 1, 110 );
	m_gridTimer->SetColSize( 2, 30 );
	m_gridTimer->EnableDragColMove( false );
	m_gridTimer->EnableDragColSize( false );
	m_gridTimer->SetColLabelValue( 0, _("Name") );
	m_gridTimer->SetColLabelValue( 1, _("Time") );
	m_gridTimer->SetColLabelValue( 2, _("R") );
	m_gridTimer->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridTimer->EnableDragRowSize( false );
	m_gridTimer->SetRowLabelSize( wxGRID_AUTOSIZE );
	m_gridTimer->SetRowLabelAlignment( wxALIGN_RIGHT, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridTimer->SetDefaultCellFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_gridTimer->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_sizerTimerMain->Add( m_gridTimer, 1, wxALL|wxEXPAND, 5 );


	m_panelTimer->SetSizer( m_sizerTimerMain );
	m_panelTimer->Layout();
	m_sizerTimerMain->Fit( m_panelTimer );
	m_notebookMain->AddPage( m_panelTimer, _("Timer"), false );
	m_panelAlarm = new wxPanel( m_notebookMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebookMain->AddPage( m_panelAlarm, _("Alarm"), false );

	m_sizerMain->Add( m_notebookMain, 1, wxEXPAND, 5 );


	this->SetSizer( m_sizerMain );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( m_timer.GetId(), wxEVT_TIMER, wxTimerEventHandler( WxTimerBase::onTimerElapsed ) );
	m_buttonStopwatchStartLap->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxTimerBase::onClickStopwatchStartLap ), NULL, this );
	m_buttonStopwatchReset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxTimerBase::onClickStopwatchReset ), NULL, this );
	m_timerButtonAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxTimerBase::onAddTimerClick ), NULL, this );
	m_timerButtonEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxTimerBase::onEditTimerClick ), NULL, this );
	m_timerButtonDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxTimerBase::onDeleteTimerClick ), NULL, this );
	m_timerButtonStartStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxTimerBase::onStartStopTimerClick ), NULL, this );
	m_timerButtonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxTimerBase::onCancelTimerClick ), NULL, this );
	m_gridTimer->Connect( wxEVT_GRID_CELL_CHANGED, wxGridEventHandler( WxTimerBase::onTimerGridCellChange ), NULL, this );
	m_gridTimer->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( WxTimerBase::onTimerGridSelectionChanged ), NULL, this );
}

WxTimerBase::~WxTimerBase()
{
}

DialogAddEditTimerBase::DialogAddEditTimerBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer7->Add( m_staticText1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlTimerName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP );
	bSizer7->Add( m_textCtrlTimerName, 6, wxALL, 5 );


	bSizer6->Add( bSizer7, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer8->Add( m_staticText2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_timePicker = new wxTimePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxTP_DEFAULT );
	bSizer8->Add( m_timePicker, 6, wxALL, 5 );


	bSizer6->Add( bSizer8, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Sound to play"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer9->Add( m_staticText4, 1, wxALL, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrlSoundFilePath = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP );
	bSizer10->Add( m_textCtrlSoundFilePath, 1, wxALL|wxEXPAND, 5 );

	m_bpButton7 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton7->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_BUTTON) ) );
	bSizer10->Add( m_bpButton7, 0, wxALL, 5 );


	bSizer9->Add( bSizer10, 0, wxEXPAND, 5 );

	m_cbLoopAudio = new wxCheckBox( this, wxID_ANY, _("Loop Audio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_cbLoopAudio, 0, wxALL, 5 );


	bSizer6->Add( bSizer9, 1, wxEXPAND, 5 );

	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton( this, wxID_OK );
	m_sdbSizer->AddButton( m_sdbSizerOK );
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();

	bSizer6->Add( m_sdbSizer, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();
	bSizer6->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_textCtrlTimerName->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DialogAddEditTimerBase::onNameChange ), NULL, this );
	m_timePicker->Connect( wxEVT_TIME_CHANGED, wxDateEventHandler( DialogAddEditTimerBase::onTimeChange ), NULL, this );
	m_textCtrlSoundFilePath->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DialogAddEditTimerBase::onFileChange ), NULL, this );
	m_bpButton7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogAddEditTimerBase::onButtonOpenClick ), NULL, this );
	m_cbLoopAudio->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogAddEditTimerBase::onCBLoopAudioChange ), NULL, this );
}

DialogAddEditTimerBase::~DialogAddEditTimerBase()
{
}

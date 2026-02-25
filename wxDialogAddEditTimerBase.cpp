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

#include "wxDialogAddEditTimerBase.h"

///////////////////////////////////////////////////////////////////////////

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

	m_observerCreationPanel = new ObserverCreationPanel(this, GetParent());
	bSizer6->Add( m_observerCreationPanel, 1, wxALL|wxEXPAND, 5 );

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
}

DialogAddEditTimerBase::~DialogAddEditTimerBase()
{
}

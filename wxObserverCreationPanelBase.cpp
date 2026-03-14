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

#include "wxObserverCreationPanelBase.h"

///////////////////////////////////////////////////////////////////////////

ObserverCreationPanelBase::ObserverCreationPanelBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( wxVERTICAL, this, _("Notification Setting") );

	m_radioBtnNothing = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Do nothing (Flash in list only)"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_radioBtnNothing->SetValue( true );
	sbSizer4->Add( m_radioBtnNothing, 0, wxALL, 5 );

	m_radioBtnAudio = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Play Sound"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_radioBtnAudio, 0, wxALL, 5 );

	wxStaticBoxSizer* m_sbSizerAudio;
	m_sbSizerAudio = new wxStaticBoxSizer( wxVERTICAL, sbSizer4->GetStaticBox(), _("Sound file") );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrlSoundFilePath = new wxTextCtrl( m_sbSizerAudio->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP );
	bSizer10->Add( m_textCtrlSoundFilePath, 1, wxALL|wxEXPAND, 5 );

	m_btnSoundFileOpen = new wxBitmapButton( m_sbSizerAudio->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnSoundFileOpen->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_BUTTON) ) );
	bSizer10->Add( m_btnSoundFileOpen, 0, wxALL, 5 );


	m_sbSizerAudio->Add( bSizer10, 0, wxEXPAND, 5 );

	m_cbLoopAudio = new wxCheckBox( m_sbSizerAudio->GetStaticBox(), wxID_ANY, _("Loop Audio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sbSizerAudio->Add( m_cbLoopAudio, 0, wxALL, 5 );


	sbSizer4->Add( m_sbSizerAudio, 0, wxEXPAND|wxLEFT, 32 );

	m_radioBtnCommand = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Execute Command"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_radioBtnCommand, 0, wxALL, 5 );

	wxStaticBoxSizer* m_sbSizerCommand;
	m_sbSizerCommand = new wxStaticBoxSizer( wxVERTICAL, sbSizer4->GetStaticBox(), _("Command") );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrlCommand = new wxTextCtrl( m_sbSizerCommand->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP );
	bSizer11->Add( m_textCtrlCommand, 1, wxALL, 5 );

	m_btnCommand = new wxBitmapButton( m_sbSizerCommand->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnCommand->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_BUTTON) ) );
	bSizer11->Add( m_btnCommand, 0, wxALL, 5 );


	m_sbSizerCommand->Add( bSizer11, 0, wxEXPAND, 5 );


	sbSizer4->Add( m_sbSizerCommand, 0, wxLEFT|wxEXPAND, 32 );

	m_radioBtnPopup = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Popup"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_radioBtnPopup, 0, wxALL, 5 );

	m_radioBtnLog2File = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Log to File"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_radioBtnLog2File, 0, wxALL, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( wxHORIZONTAL, sbSizer4->GetStaticBox(), _("File") );

	m_textCtrlLogFile = new wxTextCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP );
	sbSizer5->Add( m_textCtrlLogFile, 1, wxALL, 5 );

	m_btnLogFileOpen = new wxBitmapButton( sbSizer5->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnLogFileOpen->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_BUTTON) ) );
	sbSizer5->Add( m_btnLogFileOpen, 0, wxALL, 5 );


	bSizer4->Add( sbSizer5, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( wxHORIZONTAL, sbSizer4->GetStaticBox(), _("When expired") );

	m_textCtrlLogExpired = new wxTextCtrl( sbSizer6->GetStaticBox(), wxID_ANY, _("$N ($D) was triggered at $y-$m-$dT$h:$m:$s"), wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP );
	sbSizer6->Add( m_textCtrlLogExpired, 1, wxALL, 5 );

	m_cbLogExpiredNL = new wxCheckBox( sbSizer6->GetStaticBox(), wxID_ANY, _("NL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbLogExpiredNL->SetValue(true);
	sbSizer6->Add( m_cbLogExpiredNL, 0, wxALL|wxEXPAND, 5 );


	bSizer4->Add( sbSizer6, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( wxHORIZONTAL, sbSizer4->GetStaticBox(), _("When reset") );

	m_textCtrlLogReset = new wxTextCtrl( sbSizer7->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP );
	sbSizer7->Add( m_textCtrlLogReset, 1, wxALL, 5 );

	m_cbLogResetNL = new wxCheckBox( sbSizer7->GetStaticBox(), wxID_ANY, _("NL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbLogResetNL->SetValue(true);
	sbSizer7->Add( m_cbLogResetNL, 0, wxALL|wxEXPAND, 5 );


	bSizer4->Add( sbSizer7, 0, wxEXPAND, 5 );


	sbSizer4->Add( bSizer4, 1, wxEXPAND|wxLEFT, 32 );


	this->SetSizer( sbSizer4 );
	this->Layout();

	// Connect Events
	m_radioBtnNothing->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ObserverCreationPanelBase::onRBDoNothing ), NULL, this );
	m_radioBtnAudio->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ObserverCreationPanelBase::onRBAudio ), NULL, this );
	m_textCtrlSoundFilePath->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ObserverCreationPanelBase::onSoundFileChange ), NULL, this );
	m_btnSoundFileOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ObserverCreationPanelBase::onButtonSoundFileOpenClick ), NULL, this );
	m_cbLoopAudio->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ObserverCreationPanelBase::onCBLoopAudioChange ), NULL, this );
	m_radioBtnCommand->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ObserverCreationPanelBase::onRBCommand ), NULL, this );
	m_textCtrlCommand->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ObserverCreationPanelBase::onCommandChange ), NULL, this );
	m_btnCommand->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ObserverCreationPanelBase::onButtonCommandClick ), NULL, this );
	m_radioBtnPopup->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ObserverCreationPanelBase::onRBPopup ), NULL, this );
	m_radioBtnLog2File->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ObserverCreationPanelBase::onRBLog2File ), NULL, this );
	m_textCtrlLogFile->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ObserverCreationPanelBase::onLogFileChange ), NULL, this );
	m_btnLogFileOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ObserverCreationPanelBase::onButtonLogFileOpenClick ), NULL, this );
	m_textCtrlLogExpired->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ObserverCreationPanelBase::onLogExpiredTextChange ), NULL, this );
	m_cbLogExpiredNL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ObserverCreationPanelBase::onCBLogExpiredNL ), NULL, this );
	m_textCtrlLogReset->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ObserverCreationPanelBase::onLogResetTextChange ), NULL, this );
	m_cbLogResetNL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ObserverCreationPanelBase::onCBLogResetNL ), NULL, this );
}

ObserverCreationPanelBase::~ObserverCreationPanelBase()
{
}

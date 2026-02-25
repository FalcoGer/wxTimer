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

	m_btnFileOpen = new wxBitmapButton( m_sbSizerAudio->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnFileOpen->SetBitmap( wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_BUTTON) ) );
	bSizer10->Add( m_btnFileOpen, 0, wxALL, 5 );


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


	sbSizer4->Add( m_sbSizerCommand, 1, wxEXPAND|wxLEFT, 32 );

	m_radioBtnPopup = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Popup"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_radioBtnPopup, 0, wxALL, 5 );


	this->SetSizer( sbSizer4 );
	this->Layout();

	// Connect Events
	m_radioBtnNothing->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ObserverCreationPanelBase::onRBDoNothing ), NULL, this );
	m_radioBtnAudio->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ObserverCreationPanelBase::onRBAudio ), NULL, this );
	m_textCtrlSoundFilePath->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ObserverCreationPanelBase::onFileChange ), NULL, this );
	m_btnFileOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ObserverCreationPanelBase::onButtonOpenClick ), NULL, this );
	m_cbLoopAudio->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ObserverCreationPanelBase::onCBLoopAudioChange ), NULL, this );
	m_radioBtnCommand->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ObserverCreationPanelBase::onRBCommand ), NULL, this );
	m_textCtrlCommand->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ObserverCreationPanelBase::onCommandChange ), NULL, this );
	m_btnCommand->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ObserverCreationPanelBase::onButtonCommandClick ), NULL, this );
	m_radioBtnPopup->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ObserverCreationPanelBase::onRBPopup ), NULL, this );
}

ObserverCreationPanelBase::~ObserverCreationPanelBase()
{
}

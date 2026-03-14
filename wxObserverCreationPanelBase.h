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
#include <wx/string.h>
#include <wx/radiobut.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class ObserverCreationPanelBase
///////////////////////////////////////////////////////////////////////////////
class ObserverCreationPanelBase : public wxPanel
{
	private:

	protected:
		wxRadioButton* m_radioBtnNothing;
		wxRadioButton* m_radioBtnAudio;
		wxTextCtrl* m_textCtrlSoundFilePath;
		wxBitmapButton* m_btnSoundFileOpen;
		wxCheckBox* m_cbLoopAudio;
		wxRadioButton* m_radioBtnCommand;
		wxTextCtrl* m_textCtrlCommand;
		wxBitmapButton* m_btnCommand;
		wxRadioButton* m_radioBtnPopup;
		wxRadioButton* m_radioBtnLog2File;
		wxTextCtrl* m_textCtrlLogFile;
		wxBitmapButton* m_btnLogFileOpen;
		wxTextCtrl* m_textCtrlLogExpired;
		wxCheckBox* m_cbLogExpiredNL;
		wxTextCtrl* m_textCtrlLogReset;
		wxCheckBox* m_cbLogResetNL;

		// Virtual event handlers, override them in your derived class
		virtual void onRBDoNothing( wxCommandEvent& event ) = 0;
		virtual void onRBAudio( wxCommandEvent& event ) = 0;
		virtual void onSoundFileChange( wxCommandEvent& event ) = 0;
		virtual void onButtonSoundFileOpenClick( wxCommandEvent& event ) = 0;
		virtual void onCBLoopAudioChange( wxCommandEvent& event ) = 0;
		virtual void onRBCommand( wxCommandEvent& event ) = 0;
		virtual void onCommandChange( wxCommandEvent& event ) = 0;
		virtual void onButtonCommandClick( wxCommandEvent& event ) = 0;
		virtual void onRBPopup( wxCommandEvent& event ) = 0;
		virtual void onRBLog2File( wxCommandEvent& event ) = 0;
		virtual void onLogFileChange( wxCommandEvent& event ) = 0;
		virtual void onButtonLogFileOpenClick( wxCommandEvent& event ) = 0;
		virtual void onLogExpiredTextChange( wxCommandEvent& event ) = 0;
		virtual void onCBLogExpiredNL( wxCommandEvent& event ) = 0;
		virtual void onLogResetTextChange( wxCommandEvent& event ) = 0;
		virtual void onCBLogResetNL( wxCommandEvent& event ) = 0;


	public:

		ObserverCreationPanelBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 575,524 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~ObserverCreationPanelBase();

};


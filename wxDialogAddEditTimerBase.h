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
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/timectrl.h>
#include <wx/dateevt.h>
#include "ObserverCreationPanel.hpp"
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

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
		ObserverCreationPanel* m_observerCreationPanel;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;

		// Virtual event handlers, override them in your derived class
		virtual void onNameChange( wxCommandEvent& event ) = 0;
		virtual void onTimeChange( wxDateEvent& event ) = 0;


	public:

		DialogAddEditTimerBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Add/Edit Timer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~DialogAddEditTimerBase();

};


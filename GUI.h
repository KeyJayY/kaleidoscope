///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel1;
		wxStaticText* m_staticText1;
		wxSlider* axis;
		wxStaticText* axisNumberText;
		wxStaticText* m_staticText3;
		wxSlider* rotate;
		wxStaticText* rotateText;
		wxStaticText* m_staticText5;
		wxSlider* translateXSlider;
		wxStaticText* translationXText;
		wxStaticText* m_staticText9;
		wxSlider* translateYSlider;
		wxStaticText* translationYText;
		wxStaticText* m_staticText12;
		wxChoice* interpolator;
		wxCheckBox* drawOnChangeCheckBox;
		wxButton* loadImageButton;
		wxButton* saveSeriesButton;
		wxButton* saveButton;
		wxButton* drawButton;

		// Virtual event handlers, override them in your derived class
		virtual void scrollChangeAxisNumber( wxScrollEvent& event ) { event.Skip(); }
		virtual void scrollRotate( wxScrollEvent& event ) { event.Skip(); }
		virtual void translateX( wxScrollEvent& event ) { event.Skip(); }
		virtual void translateY( wxScrollEvent& event ) { event.Skip(); }
		virtual void changeInterpolator( wxCommandEvent& event ) { event.Skip(); }
		virtual void drawOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void loadImage( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickSaveSeries( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickDraw( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,550 ), long style = wxDEFAULT_FRAME_STYLE|wxBORDER_NONE|wxTAB_TRAVERSAL );

		~MyFrame1();

};


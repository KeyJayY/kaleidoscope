///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/colour.h>
#include <wx/dialog.h>
#include <wx/font.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/xrc/xmlres.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame {
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
    wxCheckBox* drawOnChangeCheckBox;
    wxCheckBox* drawAxisCheck;
    wxStaticText* m_staticText12;
    wxChoice* interpolator;
    wxButton* loadImageButton;
    wxButton* saveSeriesButton;
    wxButton* saveButton;
    wxButton* drawButton;
    wxStaticText* m_staticText20;

    // Virtual event handlers, override them in your derived class
    virtual void changeSize(wxSizeEvent& event) { event.Skip(); }
    virtual void drawOnPaint(wxPaintEvent& event) { event.Skip(); }
    virtual void scrollChangeAxisNumber(wxScrollEvent& event) { event.Skip(); }
    virtual void scrollRotate(wxScrollEvent& event) { event.Skip(); }
    virtual void translateX(wxScrollEvent& event) { event.Skip(); }
    virtual void translateY(wxScrollEvent& event) { event.Skip(); }
    virtual void drawOnChange(wxCommandEvent& event) { event.Skip(); }
    virtual void drawAxisChange(wxCommandEvent& event) { event.Skip(); }
    virtual void changeInterpolator(wxCommandEvent& event) { event.Skip(); }
    virtual void loadImage(wxCommandEvent& event) { event.Skip(); }
    virtual void clickSaveSeries(wxCommandEvent& event) { event.Skip(); }
    virtual void clickSave(wxCommandEvent& event) { event.Skip(); }
    virtual void clickDraw(wxCommandEvent& event) { event.Skip(); }

   public:
    MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY,
             const wxString& title = wxEmptyString,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxSize(1050, 550),
             long style = wxDEFAULT_FRAME_STYLE | wxBORDER_NONE |
                          wxTAB_TRAVERSAL);

    ~MyFrame1();
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class MyDialog1 : public wxDialog {
   private:
   protected:
    wxStaticText* m_staticText14;
    wxStaticText* m_staticText10;
    wxTextCtrl* fi1Box;
    wxStaticText* m_staticText11;
    wxTextCtrl* fi2Box;
    wxStaticLine* m_staticline1;
    wxStaticText* m_staticText16;
    wxStaticText* m_staticText12;
    wxTextCtrl* dx1Box;
    wxStaticText* m_staticText13;
    wxTextCtrl* dx2Box;
    wxStaticLine* m_staticline2;
    wxStaticText* m_staticText17;
    wxStaticText* m_staticText18;
    wxTextCtrl* dy1Box;
    wxStaticText* m_staticText19;
    wxTextCtrl* dy2Box;
    wxStaticLine* m_staticline3;
    wxButton* generateButton;

    // Virtual event handlers, override them in your derived class
    virtual void generate(wxCommandEvent& event) { event.Skip(); }

   public:
    MyDialog1(wxWindow* parent, wxWindowID id = wxID_ANY,
              const wxString& title = wxEmptyString,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxSize(550, 400),
              long style = wxDEFAULT_DIALOG_STYLE);

    ~MyDialog1();
};

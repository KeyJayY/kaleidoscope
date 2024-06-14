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
    wxStaticText* m_staticTextAxis;
    wxSlider* m_sliderAxis;
    wxStaticText* m_textAxis;
    wxStaticText* m_staticTextAngle;
    wxSlider* m_sliderAngle;
    wxStaticText* m_textAngle;
    wxStaticText* m_staticTextTranslateX;
    wxSlider* m_sliderTranslateX;
    wxStaticText* m_textTranslateX;
    wxStaticText* m_staticTextTranslateY;
    wxSlider* m_sliderTranslateY;
    wxStaticText* m_textTranslateY;
    wxStaticText* m_staticTextInterpolator;
    wxChoice* m_choiceInterpolator;
    wxCheckBox* m_checkBoxAutoUpdate;
    wxCheckBox* m_checkBoxDrawAxis;
    wxButton* m_buttonLoadImage;
    wxButton* m_buttonSaveSeries;
    wxButton* m_buttonSave;
    wxButton* m_buttonDraw;
    wxStaticText* m_textStatusBar;

    // Virtual event handlers, override them in your derived class
    virtual void changeSize(wxSizeEvent& event) { event.Skip(); }
    virtual void drawOnPaint(wxPaintEvent& event) { event.Skip(); }
    virtual void scrollChangeAxis(wxScrollEvent& event) { event.Skip(); }
    virtual void scrollChangeAngle(wxScrollEvent& event) { event.Skip(); }
    virtual void scrollChangeTranslateX(wxScrollEvent& event) { event.Skip(); }
    virtual void scrollChangeTranslateY(wxScrollEvent& event) { event.Skip(); }
    virtual void choiceChangeInterpolator(wxCommandEvent& event) {
        event.Skip();
    }
    virtual void choiceChangeAutoUpdate(wxCommandEvent& event) { event.Skip(); }
    virtual void choiceChangeDrawAxis(wxCommandEvent& event) { event.Skip(); }
    virtual void clickLoadImage(wxCommandEvent& event) { event.Skip(); }
    virtual void clickSaveSeries(wxCommandEvent& event) { event.Skip(); }
    virtual void clickSave(wxCommandEvent& event) { event.Skip(); }
    virtual void clickDraw(wxCommandEvent& event) { event.Skip(); }

   public:
    MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY,
             const wxString& title =
                 wxString::FromUTF8("GFK 30/kaleidoscope 2D 2024"),
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
    wxStaticText* m_staticTextAngle;
    wxStaticText* m_staticTextAngle1;
    wxTextCtrl* m_textCtrlAngle1;
    wxStaticText* m_staticTextAngle2;
    wxTextCtrl* m_textCtrlAngle2;
    wxStaticLine* m_staticline1;
    wxStaticText* m_staticTextTranslateX;
    wxStaticText* m_staticTextTranslateX1;
    wxTextCtrl* m_textCtrlTranslateX1;
    wxStaticText* m_staticTextTranslateX2;
    wxTextCtrl* m_textCtrlTranslateX2;
    wxStaticLine* m_staticline2;
    wxStaticText* m_staticTextTranslateY;
    wxStaticText* m_staticTextTranslateY1;
    wxTextCtrl* m_textCtrlTranslateY1;
    wxStaticText* m_staticTextTranslateY2;
    wxTextCtrl* m_textCtrlTranslateY2;
    wxStaticLine* m_staticline3;
    wxButton* m_buttonGenerate;

    // Virtual event handlers, override them in your derived class
    virtual void clickGenerate(wxCommandEvent& event) { event.Skip(); }

   public:
    MyDialog1(wxWindow* parent, wxWindowID id = wxID_ANY,
              const wxString& title = wxString::FromUTF8(
                  "GFK 30/kaleidoscope 2D 2024 - wygeneruj ciąg"),
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxSize(550, 400),
              long style = wxDEFAULT_DIALOG_STYLE);

    ~MyDialog1();
};

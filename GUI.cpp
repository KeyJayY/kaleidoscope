///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title,
                   const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxSize(950, 450), wxSize(-1, -1));

    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer(wxHORIZONTAL);

    m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(400, 400),
                           wxTAB_TRAVERSAL);
    m_panel1->SetBackgroundColour(
        wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

    bSizer1->Add(m_panel1, 0,
                 wxALIGN_CENTER_VERTICAL | wxALL | wxEXPAND | wxSHAPED, 5);

    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer(wxVERTICAL);

    bSizer2->Add(0, 0, 1, wxEXPAND, 5);

    wxBoxSizer* bSizer3;
    bSizer3 = new wxBoxSizer(wxHORIZONTAL);

    m_staticTextAxis =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("liczba osi"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextAxis->Wrap(-1);
    bSizer3->Add(m_staticTextAxis, 0, wxALIGN_CENTER | wxALL, 5);

    m_sliderAxis = new wxSlider(this, wxID_ANY, 0, 0, 20, wxDefaultPosition,
                                wxDefaultSize, wxSL_HORIZONTAL);
    bSizer3->Add(m_sliderAxis, 1, wxALIGN_CENTER | wxALL, 5);

    m_textAxis = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("0"),
                                  wxDefaultPosition, wxDefaultSize, 0);
    m_textAxis->Wrap(-1);
    bSizer3->Add(m_textAxis, 0, wxALIGN_CENTER | wxALL, 20);

    bSizer2->Add(bSizer3, 0, wxALL | wxEXPAND, 5);

    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer(wxHORIZONTAL);

    m_staticTextAngle =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("obrót o kąt"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextAngle->Wrap(-1);
    bSizer4->Add(m_staticTextAngle, 0, wxALIGN_CENTER | wxALL, 5);

    m_sliderAngle = new wxSlider(this, wxID_ANY, 0, 0, 360, wxDefaultPosition,
                                 wxDefaultSize, wxSL_HORIZONTAL);
    bSizer4->Add(m_sliderAngle, 1, wxALIGN_CENTER | wxALL, 5);

    m_textAngle = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("0"),
                                   wxDefaultPosition, wxDefaultSize, 0);
    m_textAngle->Wrap(-1);
    bSizer4->Add(m_textAngle, 0, wxALIGN_CENTER | wxALL, 20);

    bSizer2->Add(bSizer4, 0, wxALL | wxEXPAND, 5);

    wxBoxSizer* bSizer5;
    bSizer5 = new wxBoxSizer(wxHORIZONTAL);

    m_staticTextTranslateX = new wxStaticText(
        this, wxID_ANY, wxString::FromUTF8("przesuń w poziomie"),
        wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextTranslateX->Wrap(-1);
    bSizer5->Add(m_staticTextTranslateX, 0, wxALIGN_CENTER | wxALL, 5);

    m_sliderTranslateX =
        new wxSlider(this, wxID_ANY, 0, -100, 100, wxDefaultPosition,
                     wxDefaultSize, wxSL_HORIZONTAL);
    bSizer5->Add(m_sliderTranslateX, 1, wxALIGN_CENTER | wxALL, 5);

    m_textTranslateX = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("0"),
                                        wxDefaultPosition, wxDefaultSize, 0);
    m_textTranslateX->Wrap(-1);
    bSizer5->Add(m_textTranslateX, 0, wxALIGN_CENTER | wxALL, 20);

    bSizer2->Add(bSizer5, 0, wxALL | wxEXPAND, 5);

    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer(wxHORIZONTAL);

    m_staticTextTranslateY =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("przesuń w pionie"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextTranslateY->Wrap(-1);
    bSizer6->Add(m_staticTextTranslateY, 0, wxALIGN_CENTER | wxALL, 5);

    m_sliderTranslateY =
        new wxSlider(this, wxID_ANY, 0, -100, 100, wxDefaultPosition,
                     wxDefaultSize, wxSL_HORIZONTAL);
    bSizer6->Add(m_sliderTranslateY, 1, wxALIGN_CENTER | wxALL, 5);

    m_textTranslateY = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("0"),
                                        wxDefaultPosition, wxDefaultSize, 0);
    m_textTranslateY->Wrap(-1);
    bSizer6->Add(m_textTranslateY, 0, wxALIGN_CENTER | wxALL, 20);

    bSizer2->Add(bSizer6, 0, wxALL | wxEXPAND, 5);

    wxBoxSizer* bSizer7;
    bSizer7 = new wxBoxSizer(wxHORIZONTAL);

    m_staticTextInterpolator =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("interpolator:"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextInterpolator->Wrap(-1);
    bSizer7->Add(m_staticTextInterpolator, 1, wxALIGN_CENTER_VERTICAL | wxALL,
                 5);

    wxString m_choiceInterpolatorChoices[] = {wxString::FromUTF8("liniowy"),
                                              wxString::FromUTF8("kubiczny")};
    int m_choiceInterpolatorNChoices =
        sizeof(m_choiceInterpolatorChoices) / sizeof(wxString);
    m_choiceInterpolator = new wxChoice(
        this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        m_choiceInterpolatorNChoices, m_choiceInterpolatorChoices, 0);
    m_choiceInterpolator->SetSelection(0);
    bSizer7->Add(m_choiceInterpolator, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    m_checkBoxAutoUpdate = new wxCheckBox(
        this, wxID_ANY, wxString::FromUTF8("rysowanie przy każdej zmianie"),
        wxDefaultPosition, wxDefaultSize, 0);
    bSizer7->Add(m_checkBoxAutoUpdate, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    m_checkBoxDrawAxis =
        new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("rysuj osie"),
                       wxDefaultPosition, wxDefaultSize, 0);
    m_checkBoxDrawAxis->SetValue(true);
    bSizer7->Add(m_checkBoxDrawAxis, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    bSizer2->Add(bSizer7, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    wxBoxSizer* bSizer8;
    bSizer8 = new wxBoxSizer(wxHORIZONTAL);

    m_buttonLoadImage =
        new wxButton(this, wxID_ANY, wxString::FromUTF8("Wczytaj obraz"),
                     wxDefaultPosition, wxDefaultSize, 0);
    bSizer8->Add(m_buttonLoadImage, 1, wxALL, 5);

    m_buttonSaveSeries =
        new wxButton(this, wxID_ANY, wxString::FromUTF8("Wygeneruj ciąg"),
                     wxDefaultPosition, wxDefaultSize, 0);
    bSizer8->Add(m_buttonSaveSeries, 1, wxALL, 5);

    m_buttonSave = new wxButton(this, wxID_ANY, wxString::FromUTF8("Zapisz"),
                                wxDefaultPosition, wxDefaultSize, 0);
    bSizer8->Add(m_buttonSave, 1, wxALL, 5);

    m_buttonDraw = new wxButton(this, wxID_ANY, wxString::FromUTF8("Rysuj"),
                                wxDefaultPosition, wxDefaultSize, 0);
    bSizer8->Add(m_buttonDraw, 1, wxALL, 5);

    bSizer2->Add(bSizer8, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);

    bSizer2->Add(0, 0, 1, wxEXPAND, 5);

    m_textStatusBar =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("statusbar"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_textStatusBar->Wrap(-1);
    m_textStatusBar->SetForegroundColour(
        wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    m_textStatusBar->Enable(false);

    bSizer2->Add(m_textStatusBar, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

    this->SetSizer(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    this->Connect(wxEVT_SIZE, wxSizeEventHandler(MyFrame1::changeSize));
    m_panel1->Connect(wxEVT_PAINT, wxPaintEventHandler(MyFrame1::drawOnPaint),
                      NULL, this);
    m_sliderAxis->Connect(wxEVT_SCROLL_TOP,
                          wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                          NULL, this);
    m_sliderAxis->Connect(wxEVT_SCROLL_BOTTOM,
                          wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                          NULL, this);
    m_sliderAxis->Connect(wxEVT_SCROLL_LINEUP,
                          wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                          NULL, this);
    m_sliderAxis->Connect(wxEVT_SCROLL_LINEDOWN,
                          wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                          NULL, this);
    m_sliderAxis->Connect(wxEVT_SCROLL_PAGEUP,
                          wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                          NULL, this);
    m_sliderAxis->Connect(wxEVT_SCROLL_PAGEDOWN,
                          wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                          NULL, this);
    m_sliderAxis->Connect(wxEVT_SCROLL_THUMBTRACK,
                          wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                          NULL, this);
    m_sliderAxis->Connect(wxEVT_SCROLL_THUMBRELEASE,
                          wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                          NULL, this);
    m_sliderAxis->Connect(wxEVT_SCROLL_CHANGED,
                          wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                          NULL, this);
    m_sliderAngle->Connect(wxEVT_SCROLL_TOP,
                           wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                           NULL, this);
    m_sliderAngle->Connect(wxEVT_SCROLL_BOTTOM,
                           wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                           NULL, this);
    m_sliderAngle->Connect(wxEVT_SCROLL_LINEUP,
                           wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                           NULL, this);
    m_sliderAngle->Connect(wxEVT_SCROLL_LINEDOWN,
                           wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                           NULL, this);
    m_sliderAngle->Connect(wxEVT_SCROLL_PAGEUP,
                           wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                           NULL, this);
    m_sliderAngle->Connect(wxEVT_SCROLL_PAGEDOWN,
                           wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                           NULL, this);
    m_sliderAngle->Connect(wxEVT_SCROLL_THUMBTRACK,
                           wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                           NULL, this);
    m_sliderAngle->Connect(wxEVT_SCROLL_THUMBRELEASE,
                           wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                           NULL, this);
    m_sliderAngle->Connect(wxEVT_SCROLL_CHANGED,
                           wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                           NULL, this);
    m_sliderTranslateX->Connect(
        wxEVT_SCROLL_TOP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Connect(
        wxEVT_SCROLL_BOTTOM,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Connect(
        wxEVT_SCROLL_LINEUP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Connect(
        wxEVT_SCROLL_LINEDOWN,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Connect(
        wxEVT_SCROLL_PAGEUP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Connect(
        wxEVT_SCROLL_PAGEDOWN,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Connect(
        wxEVT_SCROLL_THUMBTRACK,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Connect(
        wxEVT_SCROLL_THUMBRELEASE,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Connect(
        wxEVT_SCROLL_CHANGED,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateY->Connect(
        wxEVT_SCROLL_TOP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Connect(
        wxEVT_SCROLL_BOTTOM,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Connect(
        wxEVT_SCROLL_LINEUP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Connect(
        wxEVT_SCROLL_LINEDOWN,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Connect(
        wxEVT_SCROLL_PAGEUP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Connect(
        wxEVT_SCROLL_PAGEDOWN,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Connect(
        wxEVT_SCROLL_THUMBTRACK,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Connect(
        wxEVT_SCROLL_THUMBRELEASE,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Connect(
        wxEVT_SCROLL_CHANGED,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_choiceInterpolator->Connect(
        wxEVT_COMMAND_CHOICE_SELECTED,
        wxCommandEventHandler(MyFrame1::choiceChangeInterpolator), NULL, this);
    m_checkBoxAutoUpdate->Connect(
        wxEVT_COMMAND_CHECKBOX_CLICKED,
        wxCommandEventHandler(MyFrame1::choiceChangeAutoUpdate), NULL, this);
    m_checkBoxDrawAxis->Connect(
        wxEVT_COMMAND_CHECKBOX_CLICKED,
        wxCommandEventHandler(MyFrame1::choiceChangeDrawAxis), NULL, this);
    m_buttonLoadImage->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                               wxCommandEventHandler(MyFrame1::clickLoadImage),
                               NULL, this);
    m_buttonSaveSeries->Connect(
        wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(MyFrame1::clickSaveSeries), NULL, this);
    m_buttonSave->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                          wxCommandEventHandler(MyFrame1::clickSave), NULL,
                          this);
    m_buttonDraw->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                          wxCommandEventHandler(MyFrame1::clickDraw), NULL,
                          this);
}

MyFrame1::~MyFrame1() {
    // Disconnect Events
    this->Disconnect(wxEVT_SIZE, wxSizeEventHandler(MyFrame1::changeSize));
    m_panel1->Disconnect(
        wxEVT_PAINT, wxPaintEventHandler(MyFrame1::drawOnPaint), NULL, this);
    m_sliderAxis->Disconnect(wxEVT_SCROLL_TOP,
                             wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                             NULL, this);
    m_sliderAxis->Disconnect(wxEVT_SCROLL_BOTTOM,
                             wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                             NULL, this);
    m_sliderAxis->Disconnect(wxEVT_SCROLL_LINEUP,
                             wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                             NULL, this);
    m_sliderAxis->Disconnect(wxEVT_SCROLL_LINEDOWN,
                             wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                             NULL, this);
    m_sliderAxis->Disconnect(wxEVT_SCROLL_PAGEUP,
                             wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                             NULL, this);
    m_sliderAxis->Disconnect(wxEVT_SCROLL_PAGEDOWN,
                             wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                             NULL, this);
    m_sliderAxis->Disconnect(wxEVT_SCROLL_THUMBTRACK,
                             wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                             NULL, this);
    m_sliderAxis->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                             wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                             NULL, this);
    m_sliderAxis->Disconnect(wxEVT_SCROLL_CHANGED,
                             wxScrollEventHandler(MyFrame1::scrollChangeAxis),
                             NULL, this);
    m_sliderAngle->Disconnect(wxEVT_SCROLL_TOP,
                              wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                              NULL, this);
    m_sliderAngle->Disconnect(wxEVT_SCROLL_BOTTOM,
                              wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                              NULL, this);
    m_sliderAngle->Disconnect(wxEVT_SCROLL_LINEUP,
                              wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                              NULL, this);
    m_sliderAngle->Disconnect(wxEVT_SCROLL_LINEDOWN,
                              wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                              NULL, this);
    m_sliderAngle->Disconnect(wxEVT_SCROLL_PAGEUP,
                              wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                              NULL, this);
    m_sliderAngle->Disconnect(wxEVT_SCROLL_PAGEDOWN,
                              wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                              NULL, this);
    m_sliderAngle->Disconnect(wxEVT_SCROLL_THUMBTRACK,
                              wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                              NULL, this);
    m_sliderAngle->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                              wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                              NULL, this);
    m_sliderAngle->Disconnect(wxEVT_SCROLL_CHANGED,
                              wxScrollEventHandler(MyFrame1::scrollChangeAngle),
                              NULL, this);
    m_sliderTranslateX->Disconnect(
        wxEVT_SCROLL_TOP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Disconnect(
        wxEVT_SCROLL_BOTTOM,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Disconnect(
        wxEVT_SCROLL_LINEUP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Disconnect(
        wxEVT_SCROLL_LINEDOWN,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Disconnect(
        wxEVT_SCROLL_PAGEUP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Disconnect(
        wxEVT_SCROLL_PAGEDOWN,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Disconnect(
        wxEVT_SCROLL_THUMBTRACK,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Disconnect(
        wxEVT_SCROLL_THUMBRELEASE,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateX->Disconnect(
        wxEVT_SCROLL_CHANGED,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateX), NULL, this);
    m_sliderTranslateY->Disconnect(
        wxEVT_SCROLL_TOP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Disconnect(
        wxEVT_SCROLL_BOTTOM,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Disconnect(
        wxEVT_SCROLL_LINEUP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Disconnect(
        wxEVT_SCROLL_LINEDOWN,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Disconnect(
        wxEVT_SCROLL_PAGEUP,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Disconnect(
        wxEVT_SCROLL_PAGEDOWN,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Disconnect(
        wxEVT_SCROLL_THUMBTRACK,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Disconnect(
        wxEVT_SCROLL_THUMBRELEASE,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_sliderTranslateY->Disconnect(
        wxEVT_SCROLL_CHANGED,
        wxScrollEventHandler(MyFrame1::scrollChangeTranslateY), NULL, this);
    m_choiceInterpolator->Disconnect(
        wxEVT_COMMAND_CHOICE_SELECTED,
        wxCommandEventHandler(MyFrame1::choiceChangeInterpolator), NULL, this);
    m_checkBoxAutoUpdate->Disconnect(
        wxEVT_COMMAND_CHECKBOX_CLICKED,
        wxCommandEventHandler(MyFrame1::choiceChangeAutoUpdate), NULL, this);
    m_checkBoxDrawAxis->Disconnect(
        wxEVT_COMMAND_CHECKBOX_CLICKED,
        wxCommandEventHandler(MyFrame1::choiceChangeDrawAxis), NULL, this);
    m_buttonLoadImage->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(MyFrame1::clickLoadImage), NULL, this);
    m_buttonSaveSeries->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(MyFrame1::clickSaveSeries), NULL, this);
    m_buttonSave->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                             wxCommandEventHandler(MyFrame1::clickSave), NULL,
                             this);
    m_buttonDraw->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                             wxCommandEventHandler(MyFrame1::clickDraw), NULL,
                             this);
}

MyDialog1::MyDialog1(wxWindow* parent, wxWindowID id, const wxString& title,
                     const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxSize(550, 400), wxSize(550, 400));

    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    m_staticTextAngle =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("obrót:"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextAngle->Wrap(-1);
    bSizer1->Add(m_staticTextAngle, 0, wxALL, 5);

    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer(wxHORIZONTAL);

    m_staticTextAngle1 = new wxStaticText(
        this, wxID_ANY, wxString::FromUTF8("początkowy kąt (°)"),
        wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextAngle1->Wrap(-1);
    bSizer2->Add(m_staticTextAngle1, 0, wxALIGN_CENTER | wxALL, 5);

    m_textCtrlAngle1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                                      wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(m_textCtrlAngle1, 0, wxALIGN_CENTER | wxALL, 5);

    m_staticTextAngle2 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("końcowy kąt (°)"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextAngle2->Wrap(-1);
    bSizer2->Add(m_staticTextAngle2, 0, wxALIGN_CENTER | wxALL, 5);

    m_textCtrlAngle2 = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                                      wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(m_textCtrlAngle2, 0, wxALIGN_CENTER | wxALL, 5);

    bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition,
                                     wxDefaultSize, wxLI_HORIZONTAL);
    bSizer1->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);

    m_staticTextTranslateX = new wxStaticText(
        this, wxID_ANY, wxString::FromUTF8("przesunięcie w poziomie:"),
        wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextTranslateX->Wrap(-1);
    bSizer1->Add(m_staticTextTranslateX, 0, wxALL, 5);

    wxBoxSizer* bSizer3;
    bSizer3 = new wxBoxSizer(wxHORIZONTAL);

    m_staticTextTranslateX1 = new wxStaticText(
        this, wxID_ANY, wxString::FromUTF8("początkowe dx (%)"),
        wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextTranslateX1->Wrap(-1);
    bSizer3->Add(m_staticTextTranslateX1, 0, wxALIGN_CENTER | wxALL, 5);

    m_textCtrlTranslateX1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                                           wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(m_textCtrlTranslateX1, 0, wxALIGN_CENTER | wxALL, 5);

    m_staticTextTranslateX2 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("końcowe dx (%)"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextTranslateX2->Wrap(-1);
    bSizer3->Add(m_staticTextTranslateX2, 0, wxALIGN_CENTER | wxALL, 5);

    m_textCtrlTranslateX2 = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                                           wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(m_textCtrlTranslateX2, 0, wxALIGN_CENTER | wxALL, 5);

    bSizer1->Add(bSizer3, 1, wxEXPAND, 5);

    m_staticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition,
                                     wxDefaultSize, wxLI_HORIZONTAL);
    bSizer1->Add(m_staticline2, 0, wxEXPAND | wxALL, 5);

    m_staticTextTranslateY = new wxStaticText(
        this, wxID_ANY, wxString::FromUTF8("przesunięcie w pionie"),
        wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextTranslateY->Wrap(-1);
    bSizer1->Add(m_staticTextTranslateY, 0, wxALL, 5);

    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer(wxHORIZONTAL);

    m_staticTextTranslateY1 = new wxStaticText(
        this, wxID_ANY, wxString::FromUTF8("początkowe dy (%)"),
        wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextTranslateY1->Wrap(-1);
    bSizer4->Add(m_staticTextTranslateY1, 0, wxALIGN_CENTER | wxALL, 5);

    m_textCtrlTranslateY1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                                           wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(m_textCtrlTranslateY1, 0, wxALIGN_CENTER | wxALL, 5);

    m_staticTextTranslateY2 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("końcowe dy (%)"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextTranslateY2->Wrap(-1);
    bSizer4->Add(m_staticTextTranslateY2, 0, wxALIGN_CENTER | wxALL, 5);

    m_textCtrlTranslateY2 = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                                           wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(m_textCtrlTranslateY2, 0, wxALIGN_CENTER | wxALL, 5);

    bSizer1->Add(bSizer4, 1, wxEXPAND, 5);

    m_staticline3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition,
                                     wxDefaultSize, wxLI_HORIZONTAL);
    bSizer1->Add(m_staticline3, 0, wxEXPAND | wxALL, 5);

    m_buttonGenerate =
        new wxButton(this, wxID_ANY, wxString::FromUTF8("Generuj"),
                     wxDefaultPosition, wxDefaultSize, 0);
    bSizer1->Add(m_buttonGenerate, 0, wxALIGN_RIGHT | wxALL, 5);

    this->SetSizer(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    m_buttonGenerate->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                              wxCommandEventHandler(MyDialog1::clickGenerate),
                              NULL, this);
}

MyDialog1::~MyDialog1() {
    // Disconnect Events
    m_buttonGenerate->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(MyDialog1::clickGenerate), NULL, this);
}

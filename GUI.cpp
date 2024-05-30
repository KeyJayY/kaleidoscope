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

    bSizer1->Add(m_panel1, 0, wxALIGN_CENTER | wxALL | wxEXPAND | wxSHAPED, 5);

    wxBoxSizer* bSizer7;
    bSizer7 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* bSizer3;
    bSizer3 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText1 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("liczba osi"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->Wrap(-1);
    bSizer3->Add(m_staticText1, 0, wxALIGN_CENTER | wxALL, 5);

    axis = new wxSlider(this, wxID_ANY, 0, 0, 20, wxDefaultPosition,
                        wxDefaultSize, wxSL_HORIZONTAL);
    bSizer3->Add(axis, 1, wxALIGN_CENTER | wxALL, 5);

    axisNumberText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("0"),
                                      wxDefaultPosition, wxDefaultSize, 0);
    axisNumberText->Wrap(-1);
    bSizer3->Add(axisNumberText, 0, wxALIGN_CENTER | wxALL, 20);

    bSizer7->Add(bSizer3, 1, wxEXPAND | wxLEFT | wxRIGHT, 5);

    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText3 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("obrót o kąt"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticText3->Wrap(-1);
    bSizer4->Add(m_staticText3, 0, wxALIGN_CENTER | wxALL, 5);

    rotate = new wxSlider(this, wxID_ANY, 0, 0, 360, wxDefaultPosition,
                          wxDefaultSize, wxSL_HORIZONTAL);
    bSizer4->Add(rotate, 1, wxALIGN_CENTER | wxALL, 5);

    rotateText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("0"),
                                  wxDefaultPosition, wxDefaultSize, 0);
    rotateText->Wrap(-1);
    bSizer4->Add(rotateText, 0, wxALIGN_CENTER | wxALL, 20);

    bSizer7->Add(bSizer4, 1, wxEXPAND | wxLEFT | wxRIGHT, 5);

    wxBoxSizer* bSizer5;
    bSizer5 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText5 = new wxStaticText(this, wxID_ANY,
                                     wxString::FromUTF8("przesuń w poziomie"),
                                     wxDefaultPosition, wxDefaultSize, 0);
    m_staticText5->Wrap(-1);
    bSizer5->Add(m_staticText5, 0, wxALIGN_CENTER | wxALL, 5);

    translateXSlider =
        new wxSlider(this, wxID_ANY, 0, -100, 100, wxDefaultPosition,
                     wxDefaultSize, wxSL_HORIZONTAL);
    bSizer5->Add(translateXSlider, 1, wxALIGN_CENTER | wxALL, 5);

    translationXText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("0"),
                                        wxDefaultPosition, wxDefaultSize, 0);
    translationXText->Wrap(-1);
    bSizer5->Add(translationXText, 0, wxALIGN_CENTER | wxALL, 20);

    bSizer7->Add(bSizer5, 1, wxEXPAND | wxLEFT | wxRIGHT, 5);

    wxBoxSizer* bSizer8;
    bSizer8 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText9 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("przesuń w pionie"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticText9->Wrap(-1);
    bSizer8->Add(m_staticText9, 0, wxALIGN_CENTER | wxALL, 5);

    translateYSlider =
        new wxSlider(this, wxID_ANY, 0, -100, 100, wxDefaultPosition,
                     wxDefaultSize, wxSL_HORIZONTAL);
    bSizer8->Add(translateYSlider, 1, wxALIGN_CENTER | wxALL, 5);

    translationYText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("0"),
                                        wxDefaultPosition, wxDefaultSize, 0);
    translationYText->Wrap(-1);
    bSizer8->Add(translationYText, 0, wxALIGN_CENTER | wxALL, 20);

    bSizer7->Add(bSizer8, 1, wxEXPAND | wxLEFT | wxRIGHT, 5);

    wxBoxSizer* bSizer91;
    bSizer91 = new wxBoxSizer(wxHORIZONTAL);

    drawOnChangeCheckBox = new wxCheckBox(
        this, wxID_ANY, wxString::FromUTF8("rysowanie przy każdej zmianie"),
        wxDefaultPosition, wxDefaultSize, 0);
    bSizer91->Add(drawOnChangeCheckBox, 0, wxALL | wxEXPAND, 5);

    drawAxisCheck =
        new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("rysuj osie"),
                       wxDefaultPosition, wxDefaultSize, 0);
    drawAxisCheck->SetValue(true);
    bSizer91->Add(drawAxisCheck, 0, wxALIGN_CENTER | wxALL, 5);

    bSizer7->Add(bSizer91, 0, wxALIGN_CENTER, 5);

    wxBoxSizer* bSizer9;
    bSizer9 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText12 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("interpolator"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticText12->Wrap(-1);
    bSizer9->Add(m_staticText12, 1, wxALIGN_CENTER | wxALL, 5);

    wxString interpolatorChoices[] = {wxString::FromUTF8("liniowy"),
                                      wxString::FromUTF8("kubiczny")};
    int interpolatorNChoices = sizeof(interpolatorChoices) / sizeof(wxString);
    interpolator =
        new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                     interpolatorNChoices, interpolatorChoices, 0);
    interpolator->SetSelection(0);
    bSizer9->Add(interpolator, 0, wxALIGN_CENTER | wxALL, 5);

    bSizer7->Add(bSizer9, 1, wxALIGN_CENTER, 5);

    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer(wxHORIZONTAL);

    bSizer6->Add(0, 0, 1, wxEXPAND, 5);

    loadImageButton =
        new wxButton(this, wxID_ANY, wxString::FromUTF8("Wczytaj obraz"),
                     wxDefaultPosition, wxDefaultSize, 0);
    bSizer6->Add(loadImageButton, 0, wxALL, 5);

    bSizer6->Add(0, 0, 1, wxEXPAND, 5);

    saveSeriesButton =
        new wxButton(this, wxID_ANY, wxString::FromUTF8("Wygeneruj ciąg"),
                     wxDefaultPosition, wxDefaultSize, 0);
    bSizer6->Add(saveSeriesButton, 0, wxALL, 5);

    bSizer6->Add(0, 0, 1, wxEXPAND, 5);

    saveButton = new wxButton(this, wxID_ANY, wxString::FromUTF8("Zapisz"),
                              wxDefaultPosition, wxDefaultSize, 0);
    bSizer6->Add(saveButton, 0, wxALL, 5);

    bSizer6->Add(0, 0, 1, wxEXPAND, 5);

    drawButton = new wxButton(this, wxID_ANY, wxString::FromUTF8("Rysuj"),
                              wxDefaultPosition, wxDefaultSize, 0);
    bSizer6->Add(drawButton, 0, wxALL, 5);

    bSizer6->Add(0, 0, 1, wxEXPAND, 5);

    bSizer7->Add(bSizer6, 1, wxEXPAND | wxLEFT | wxRIGHT, 5);

    m_staticText20 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("statusbar"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticText20->Wrap(-1);
    m_staticText20->SetForegroundColour(
        wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    m_staticText20->Enable(false);

    bSizer7->Add(m_staticText20, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    bSizer1->Add(bSizer7, 1, wxALIGN_CENTER_HORIZONTAL | wxEXPAND, 5);

    this->SetSizer(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    this->Connect(wxEVT_SIZE, wxSizeEventHandler(MyFrame1::changeSize));
    m_panel1->Connect(wxEVT_PAINT, wxPaintEventHandler(MyFrame1::drawOnPaint),
                      NULL, this);
    axis->Connect(wxEVT_SCROLL_TOP,
                  wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber), NULL,
                  this);
    axis->Connect(wxEVT_SCROLL_BOTTOM,
                  wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber), NULL,
                  this);
    axis->Connect(wxEVT_SCROLL_LINEUP,
                  wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber), NULL,
                  this);
    axis->Connect(wxEVT_SCROLL_LINEDOWN,
                  wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber), NULL,
                  this);
    axis->Connect(wxEVT_SCROLL_PAGEUP,
                  wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber), NULL,
                  this);
    axis->Connect(wxEVT_SCROLL_PAGEDOWN,
                  wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber), NULL,
                  this);
    axis->Connect(wxEVT_SCROLL_THUMBTRACK,
                  wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber), NULL,
                  this);
    axis->Connect(wxEVT_SCROLL_THUMBRELEASE,
                  wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber), NULL,
                  this);
    axis->Connect(wxEVT_SCROLL_CHANGED,
                  wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber), NULL,
                  this);
    rotate->Connect(wxEVT_SCROLL_TOP,
                    wxScrollEventHandler(MyFrame1::scrollRotate), NULL, this);
    rotate->Connect(wxEVT_SCROLL_BOTTOM,
                    wxScrollEventHandler(MyFrame1::scrollRotate), NULL, this);
    rotate->Connect(wxEVT_SCROLL_LINEUP,
                    wxScrollEventHandler(MyFrame1::scrollRotate), NULL, this);
    rotate->Connect(wxEVT_SCROLL_LINEDOWN,
                    wxScrollEventHandler(MyFrame1::scrollRotate), NULL, this);
    rotate->Connect(wxEVT_SCROLL_PAGEUP,
                    wxScrollEventHandler(MyFrame1::scrollRotate), NULL, this);
    rotate->Connect(wxEVT_SCROLL_PAGEDOWN,
                    wxScrollEventHandler(MyFrame1::scrollRotate), NULL, this);
    rotate->Connect(wxEVT_SCROLL_THUMBTRACK,
                    wxScrollEventHandler(MyFrame1::scrollRotate), NULL, this);
    rotate->Connect(wxEVT_SCROLL_THUMBRELEASE,
                    wxScrollEventHandler(MyFrame1::scrollRotate), NULL, this);
    rotate->Connect(wxEVT_SCROLL_CHANGED,
                    wxScrollEventHandler(MyFrame1::scrollRotate), NULL, this);
    translateXSlider->Connect(wxEVT_SCROLL_TOP,
                              wxScrollEventHandler(MyFrame1::translateX), NULL,
                              this);
    translateXSlider->Connect(wxEVT_SCROLL_BOTTOM,
                              wxScrollEventHandler(MyFrame1::translateX), NULL,
                              this);
    translateXSlider->Connect(wxEVT_SCROLL_LINEUP,
                              wxScrollEventHandler(MyFrame1::translateX), NULL,
                              this);
    translateXSlider->Connect(wxEVT_SCROLL_LINEDOWN,
                              wxScrollEventHandler(MyFrame1::translateX), NULL,
                              this);
    translateXSlider->Connect(wxEVT_SCROLL_PAGEUP,
                              wxScrollEventHandler(MyFrame1::translateX), NULL,
                              this);
    translateXSlider->Connect(wxEVT_SCROLL_PAGEDOWN,
                              wxScrollEventHandler(MyFrame1::translateX), NULL,
                              this);
    translateXSlider->Connect(wxEVT_SCROLL_THUMBTRACK,
                              wxScrollEventHandler(MyFrame1::translateX), NULL,
                              this);
    translateXSlider->Connect(wxEVT_SCROLL_THUMBRELEASE,
                              wxScrollEventHandler(MyFrame1::translateX), NULL,
                              this);
    translateXSlider->Connect(wxEVT_SCROLL_CHANGED,
                              wxScrollEventHandler(MyFrame1::translateX), NULL,
                              this);
    translateYSlider->Connect(wxEVT_SCROLL_TOP,
                              wxScrollEventHandler(MyFrame1::translateY), NULL,
                              this);
    translateYSlider->Connect(wxEVT_SCROLL_BOTTOM,
                              wxScrollEventHandler(MyFrame1::translateY), NULL,
                              this);
    translateYSlider->Connect(wxEVT_SCROLL_LINEUP,
                              wxScrollEventHandler(MyFrame1::translateY), NULL,
                              this);
    translateYSlider->Connect(wxEVT_SCROLL_LINEDOWN,
                              wxScrollEventHandler(MyFrame1::translateY), NULL,
                              this);
    translateYSlider->Connect(wxEVT_SCROLL_PAGEUP,
                              wxScrollEventHandler(MyFrame1::translateY), NULL,
                              this);
    translateYSlider->Connect(wxEVT_SCROLL_PAGEDOWN,
                              wxScrollEventHandler(MyFrame1::translateY), NULL,
                              this);
    translateYSlider->Connect(wxEVT_SCROLL_THUMBTRACK,
                              wxScrollEventHandler(MyFrame1::translateY), NULL,
                              this);
    translateYSlider->Connect(wxEVT_SCROLL_THUMBRELEASE,
                              wxScrollEventHandler(MyFrame1::translateY), NULL,
                              this);
    translateYSlider->Connect(wxEVT_SCROLL_CHANGED,
                              wxScrollEventHandler(MyFrame1::translateY), NULL,
                              this);
    drawOnChangeCheckBox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED,
                                  wxCommandEventHandler(MyFrame1::drawOnChange),
                                  NULL, this);
    drawAxisCheck->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED,
                           wxCommandEventHandler(MyFrame1::drawAxisChange),
                           NULL, this);
    interpolator->Connect(wxEVT_COMMAND_CHOICE_SELECTED,
                          wxCommandEventHandler(MyFrame1::changeInterpolator),
                          NULL, this);
    loadImageButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                             wxCommandEventHandler(MyFrame1::loadImage), NULL,
                             this);
    saveSeriesButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                              wxCommandEventHandler(MyFrame1::clickSaveSeries),
                              NULL, this);
    saveButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                        wxCommandEventHandler(MyFrame1::clickSave), NULL, this);
    drawButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                        wxCommandEventHandler(MyFrame1::clickDraw), NULL, this);
}

MyFrame1::~MyFrame1() {
    // Disconnect Events
    this->Disconnect(wxEVT_SIZE, wxSizeEventHandler(MyFrame1::changeSize));
    m_panel1->Disconnect(
        wxEVT_PAINT, wxPaintEventHandler(MyFrame1::drawOnPaint), NULL, this);
    axis->Disconnect(wxEVT_SCROLL_TOP,
                     wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber),
                     NULL, this);
    axis->Disconnect(wxEVT_SCROLL_BOTTOM,
                     wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber),
                     NULL, this);
    axis->Disconnect(wxEVT_SCROLL_LINEUP,
                     wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber),
                     NULL, this);
    axis->Disconnect(wxEVT_SCROLL_LINEDOWN,
                     wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber),
                     NULL, this);
    axis->Disconnect(wxEVT_SCROLL_PAGEUP,
                     wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber),
                     NULL, this);
    axis->Disconnect(wxEVT_SCROLL_PAGEDOWN,
                     wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber),
                     NULL, this);
    axis->Disconnect(wxEVT_SCROLL_THUMBTRACK,
                     wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber),
                     NULL, this);
    axis->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                     wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber),
                     NULL, this);
    axis->Disconnect(wxEVT_SCROLL_CHANGED,
                     wxScrollEventHandler(MyFrame1::scrollChangeAxisNumber),
                     NULL, this);
    rotate->Disconnect(wxEVT_SCROLL_TOP,
                       wxScrollEventHandler(MyFrame1::scrollRotate), NULL,
                       this);
    rotate->Disconnect(wxEVT_SCROLL_BOTTOM,
                       wxScrollEventHandler(MyFrame1::scrollRotate), NULL,
                       this);
    rotate->Disconnect(wxEVT_SCROLL_LINEUP,
                       wxScrollEventHandler(MyFrame1::scrollRotate), NULL,
                       this);
    rotate->Disconnect(wxEVT_SCROLL_LINEDOWN,
                       wxScrollEventHandler(MyFrame1::scrollRotate), NULL,
                       this);
    rotate->Disconnect(wxEVT_SCROLL_PAGEUP,
                       wxScrollEventHandler(MyFrame1::scrollRotate), NULL,
                       this);
    rotate->Disconnect(wxEVT_SCROLL_PAGEDOWN,
                       wxScrollEventHandler(MyFrame1::scrollRotate), NULL,
                       this);
    rotate->Disconnect(wxEVT_SCROLL_THUMBTRACK,
                       wxScrollEventHandler(MyFrame1::scrollRotate), NULL,
                       this);
    rotate->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                       wxScrollEventHandler(MyFrame1::scrollRotate), NULL,
                       this);
    rotate->Disconnect(wxEVT_SCROLL_CHANGED,
                       wxScrollEventHandler(MyFrame1::scrollRotate), NULL,
                       this);
    translateXSlider->Disconnect(wxEVT_SCROLL_TOP,
                                 wxScrollEventHandler(MyFrame1::translateX),
                                 NULL, this);
    translateXSlider->Disconnect(wxEVT_SCROLL_BOTTOM,
                                 wxScrollEventHandler(MyFrame1::translateX),
                                 NULL, this);
    translateXSlider->Disconnect(wxEVT_SCROLL_LINEUP,
                                 wxScrollEventHandler(MyFrame1::translateX),
                                 NULL, this);
    translateXSlider->Disconnect(wxEVT_SCROLL_LINEDOWN,
                                 wxScrollEventHandler(MyFrame1::translateX),
                                 NULL, this);
    translateXSlider->Disconnect(wxEVT_SCROLL_PAGEUP,
                                 wxScrollEventHandler(MyFrame1::translateX),
                                 NULL, this);
    translateXSlider->Disconnect(wxEVT_SCROLL_PAGEDOWN,
                                 wxScrollEventHandler(MyFrame1::translateX),
                                 NULL, this);
    translateXSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK,
                                 wxScrollEventHandler(MyFrame1::translateX),
                                 NULL, this);
    translateXSlider->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                                 wxScrollEventHandler(MyFrame1::translateX),
                                 NULL, this);
    translateXSlider->Disconnect(wxEVT_SCROLL_CHANGED,
                                 wxScrollEventHandler(MyFrame1::translateX),
                                 NULL, this);
    translateYSlider->Disconnect(wxEVT_SCROLL_TOP,
                                 wxScrollEventHandler(MyFrame1::translateY),
                                 NULL, this);
    translateYSlider->Disconnect(wxEVT_SCROLL_BOTTOM,
                                 wxScrollEventHandler(MyFrame1::translateY),
                                 NULL, this);
    translateYSlider->Disconnect(wxEVT_SCROLL_LINEUP,
                                 wxScrollEventHandler(MyFrame1::translateY),
                                 NULL, this);
    translateYSlider->Disconnect(wxEVT_SCROLL_LINEDOWN,
                                 wxScrollEventHandler(MyFrame1::translateY),
                                 NULL, this);
    translateYSlider->Disconnect(wxEVT_SCROLL_PAGEUP,
                                 wxScrollEventHandler(MyFrame1::translateY),
                                 NULL, this);
    translateYSlider->Disconnect(wxEVT_SCROLL_PAGEDOWN,
                                 wxScrollEventHandler(MyFrame1::translateY),
                                 NULL, this);
    translateYSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK,
                                 wxScrollEventHandler(MyFrame1::translateY),
                                 NULL, this);
    translateYSlider->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                                 wxScrollEventHandler(MyFrame1::translateY),
                                 NULL, this);
    translateYSlider->Disconnect(wxEVT_SCROLL_CHANGED,
                                 wxScrollEventHandler(MyFrame1::translateY),
                                 NULL, this);
    drawOnChangeCheckBox->Disconnect(
        wxEVT_COMMAND_CHECKBOX_CLICKED,
        wxCommandEventHandler(MyFrame1::drawOnChange), NULL, this);
    drawAxisCheck->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED,
                              wxCommandEventHandler(MyFrame1::drawAxisChange),
                              NULL, this);
    interpolator->Disconnect(
        wxEVT_COMMAND_CHOICE_SELECTED,
        wxCommandEventHandler(MyFrame1::changeInterpolator), NULL, this);
    loadImageButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                wxCommandEventHandler(MyFrame1::loadImage),
                                NULL, this);
    saveSeriesButton->Disconnect(
        wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(MyFrame1::clickSaveSeries), NULL, this);
    saveButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                           wxCommandEventHandler(MyFrame1::clickSave), NULL,
                           this);
    drawButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                           wxCommandEventHandler(MyFrame1::clickDraw), NULL,
                           this);
}

MyDialog1::MyDialog1(wxWindow* parent, wxWindowID id, const wxString& title,
                     const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxSize(550, 400), wxSize(550, 400));

    wxBoxSizer* bSizer10;
    bSizer10 = new wxBoxSizer(wxVERTICAL);

    m_staticText14 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("obrót:"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticText14->Wrap(-1);
    bSizer10->Add(m_staticText14, 0, wxALL, 5);

    wxBoxSizer* bSizer11;
    bSizer11 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText10 = new wxStaticText(this, wxID_ANY,
                                      wxString::FromUTF8("początkowy kąt (°)"),
                                      wxDefaultPosition, wxDefaultSize, 0);
    m_staticText10->Wrap(-1);
    bSizer11->Add(m_staticText10, 0, wxALIGN_CENTER | wxALL, 5);

    fi1Box = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
                            wxDefaultSize, 0);
    bSizer11->Add(fi1Box, 0, wxALIGN_CENTER | wxALL, 5);

    m_staticText11 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("końcowy kąt (°)"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticText11->Wrap(-1);
    bSizer11->Add(m_staticText11, 0, wxALIGN_CENTER | wxALL, 5);

    fi2Box = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
                            wxDefaultSize, 0);
    bSizer11->Add(fi2Box, 0, wxALIGN_CENTER | wxALL, 5);

    bSizer10->Add(bSizer11, 1, wxEXPAND, 5);

    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition,
                                     wxDefaultSize, wxLI_HORIZONTAL);
    bSizer10->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);

    m_staticText16 = new wxStaticText(
        this, wxID_ANY, wxString::FromUTF8("przesunięcie w poziomie:"),
        wxDefaultPosition, wxDefaultSize, 0);
    m_staticText16->Wrap(-1);
    bSizer10->Add(m_staticText16, 0, wxALL, 5);

    wxBoxSizer* bSizer13;
    bSizer13 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText12 = new wxStaticText(this, wxID_ANY,
                                      wxString::FromUTF8("początkowe dx (%)"),
                                      wxDefaultPosition, wxDefaultSize, 0);
    m_staticText12->Wrap(-1);
    bSizer13->Add(m_staticText12, 0, wxALIGN_CENTER | wxALL, 5);

    dx1Box = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
                            wxDefaultSize, 0);
    bSizer13->Add(dx1Box, 0, wxALIGN_CENTER | wxALL, 5);

    m_staticText13 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("końcowe dx (%)"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticText13->Wrap(-1);
    bSizer13->Add(m_staticText13, 0, wxALIGN_CENTER | wxALL, 5);

    dx2Box = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
                            wxDefaultSize, 0);
    bSizer13->Add(dx2Box, 0, wxALIGN_CENTER | wxALL, 5);

    bSizer10->Add(bSizer13, 1, wxEXPAND, 5);

    m_staticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition,
                                     wxDefaultSize, wxLI_HORIZONTAL);
    bSizer10->Add(m_staticline2, 0, wxEXPAND | wxALL, 5);

    m_staticText17 = new wxStaticText(
        this, wxID_ANY, wxString::FromUTF8("przesunięcie w pionie"),
        wxDefaultPosition, wxDefaultSize, 0);
    m_staticText17->Wrap(-1);
    bSizer10->Add(m_staticText17, 0, wxALL, 5);

    wxBoxSizer* bSizer14;
    bSizer14 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText18 = new wxStaticText(this, wxID_ANY,
                                      wxString::FromUTF8("początkowe dy (%)"),
                                      wxDefaultPosition, wxDefaultSize, 0);
    m_staticText18->Wrap(-1);
    bSizer14->Add(m_staticText18, 0, wxALIGN_CENTER | wxALL, 5);

    dy1Box = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
                            wxDefaultSize, 0);
    bSizer14->Add(dy1Box, 0, wxALIGN_CENTER | wxALL, 5);

    m_staticText19 =
        new wxStaticText(this, wxID_ANY, wxString::FromUTF8("końcowe dy (%)"),
                         wxDefaultPosition, wxDefaultSize, 0);
    m_staticText19->Wrap(-1);
    bSizer14->Add(m_staticText19, 0, wxALIGN_CENTER | wxALL, 5);

    dy2Box = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
                            wxDefaultSize, 0);
    bSizer14->Add(dy2Box, 0, wxALIGN_CENTER | wxALL, 5);

    bSizer10->Add(bSizer14, 1, wxEXPAND, 5);

    m_staticline3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition,
                                     wxDefaultSize, wxLI_HORIZONTAL);
    bSizer10->Add(m_staticline3, 0, wxEXPAND | wxALL, 5);

    generateButton = new wxButton(this, wxID_ANY, wxString::FromUTF8("Generuj"),
                                  wxDefaultPosition, wxDefaultSize, 0);
    bSizer10->Add(generateButton, 0, wxALIGN_RIGHT | wxALL, 5);

    this->SetSizer(bSizer10);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    generateButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                            wxCommandEventHandler(MyDialog1::generate), NULL,
                            this);
}

MyDialog1::~MyDialog1() {
    // Disconnect Events
    generateButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                               wxCommandEventHandler(MyDialog1::generate), NULL,
                               this);
}

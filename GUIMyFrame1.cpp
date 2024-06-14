#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent) {
    wxInitAllImageHandlers();
    Bind(
        wxEVT_COMMAND_BUTTON_CLICKED,
        [&](wxCommandEvent& event) {
            if (dlg != nullptr) {
                dlg->EndModal(wxID_OK);
                dlg->Destroy();
                dlg = nullptr;
            }
        },
        ID_WINDOW);
    Bind(
        wxEVT_COMMAND_BUTTON_CLICKED,
        [&](wxCommandEvent& event) {
            int progress = event.GetInt();
            if (dlg && dlg->progressBar) {
                dlg->progressBar->SetValue(progress);
            }
        },
        ID_UPDATE_PROGRESS);
    resizeTimer.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
        gen.setSide(m_panel1->GetSize().x);
        Repaint();
    });
    // this->SetDoubleBuffered(true);
}

void GUIMyFrame1::changeSize(wxSizeEvent& event) {
    resizeTimer.Start(100, wxTIMER_ONE_SHOT);
    event.Skip();
}

void GUIMyFrame1::drawOnPaint(wxPaintEvent& event) {
    if (!gen.isImageLoaded()) return;
    wxPaintDC dc(m_panel1);
    dc.DrawBitmap(gen.getBitmap(), 0, 0, true);
    auto millis = gen.getLastUpdateMillis();
    auto timeText = std::format("{:.3} ms / {:.1f} FPS", millis, 1000 / millis);
    m_textStatusBar->SetLabelText(timeText);
}

void GUIMyFrame1::Paint() {
    if (!gen.isImageLoaded()) return;
    wxClientDC dc(m_panel1);
    dc.SetBrush(*wxBLACK_BRUSH);
    dc.DrawBitmap(wxBitmap(gen.getImage()), 0, 0, true);
    auto millis = gen.getLastUpdateMillis();
    auto timeText = std::format("{:.3} ms / {:.1f} FPS", millis, 1000 / millis);
    m_textStatusBar->SetLabelText(timeText);
}

void GUIMyFrame1::Repaint() {
#ifdef _WIN32
    Paint();
#else
    Refresh();
#endif
}

void GUIMyFrame1::scrollChangeAxis(wxScrollEvent& event) {
    m_textAxis->SetLabel(std::to_string(m_sliderAxis->GetValue()));
    gen.setAxis(m_sliderAxis->GetValue());
    if (auto_update) Repaint();
}

void GUIMyFrame1::scrollChangeAngle(wxScrollEvent& event) {
    m_textAngle->SetLabel(std::to_string(m_sliderAngle->GetValue()));
    gen.setAngle(m_sliderAngle->GetValue());
    if (auto_update) Repaint();
}

void GUIMyFrame1::scrollChangeTranslateX(wxScrollEvent& event) {
    m_textTranslateX->SetLabel(std::to_string(m_sliderTranslateX->GetValue()));
    gen.setTranslateX(m_sliderTranslateX->GetValue() / 100.0);
    if (auto_update) Repaint();
}

void GUIMyFrame1::scrollChangeTranslateY(wxScrollEvent& event) {
    m_textTranslateY->SetLabel(std::to_string(m_sliderTranslateY->GetValue()));
    gen.setTranslateY(m_sliderTranslateY->GetValue() / 100.0);
    if (auto_update) Repaint();
}

void GUIMyFrame1::choiceChangeInterpolator(wxCommandEvent& event) {
    gen.setInterpolation(Kaleidoscope::InterpolationMethod(
        m_choiceInterpolator->GetSelection()));
    if (auto_update) Repaint();
}

void GUIMyFrame1::choiceChangeAutoUpdate(wxCommandEvent& event) {
    auto_update = m_checkBoxAutoUpdate->GetValue();
    if (auto_update) Repaint();
}

void GUIMyFrame1::choiceChangeDrawAxis(wxCommandEvent& event) {
    gen.setDrawAxis(m_checkBoxDrawAxis->GetValue());
    if (auto_update) Repaint();
}

void GUIMyFrame1::clickLoadImage(wxCommandEvent& event) {
    wxFileDialog openFileDialog(
        this, _("Wybierz obraz"), "", "",
        "Wszystkie pliki obrazów (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL) return;

    resetOptions();
    wxString imagePath = openFileDialog.GetPath();
    gen.setImage(wxImage(imagePath));
    Repaint();
}

void GUIMyFrame1::clickSaveSeries(wxCommandEvent& event) {
    if (ensureImageLoaded()) return;
    GUIMyDialog1 window(this);
    window.ShowModal();
    if (window.isOk) {
        wxDirDialog dirDialog(this, _("Wybierz katalog"), "",
                              wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

        if (dirDialog.ShowModal() == wxID_CANCEL) return;

        wxString directoryPath = dirDialog.GetPath();
        SeriesWorkerThread* thread =
            new SeriesWorkerThread(this, directoryPath, window.config);
        if (thread->Run() != wxTHREAD_NO_ERROR) {
            delete thread;
            wxMessageBox("Nie można uruchomić wątku!", "Błąd", wxICON_ERROR);
        } else {
            dlg = new LoadingDialog(this);
            dlg->ShowModal();
        }
    }
}

void GUIMyFrame1::clickSave(wxCommandEvent& event) {
    if (ensureImageLoaded()) return;
    wxFileDialog saveFileDialog(
        this, _("Zapisz obraz jako..."), "", "",
        "Pliki JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg|Pliki PNG (*.png)|*.png",
        wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL) return;

    wxString filePath = saveFileDialog.GetPath();

    wxBitmapType fileType = wxBITMAP_TYPE_ANY;
    if (filePath.EndsWith(".jpg") || filePath.EndsWith(".jpeg")) {
        fileType = wxBITMAP_TYPE_JPEG;
    } else if (filePath.EndsWith(".png")) {
        fileType = wxBITMAP_TYPE_PNG;
    }

    if (!gen.getImage().SaveFile(filePath, fileType)) {
        wxMessageBox(
            wxString::FromUTF8(
                "Nieznane rozszerzenie albo brak uprawnień do zapisu?"),
            wxString::FromUTF8("Nie można zapisać obrazu!"));
    }
}

void GUIMyFrame1::clickDraw(wxCommandEvent& event) { Repaint(); }

void GUIMyFrame1::resetOptions() {
    gen.resetParameters();
    m_sliderAxis->SetValue(0);
    m_sliderAngle->SetValue(0);
    m_sliderTranslateX->SetValue(0);
    m_sliderTranslateY->SetValue(0);
    m_textAxis->SetLabel("0");
    m_textAngle->SetLabel("0");
    m_textTranslateX->SetLabel("0");
    m_textTranslateY->SetLabel("0");
}

bool GUIMyFrame1::ensureImageLoaded() {
    if (gen.isImageLoaded()) return false;
    wxMessageBox("Nie wczytano obrazu.", "Nie wczytano obrazu",
                 wxOK | wxICON_ERROR);
    return true;
}

void GUIMyFrame1::generateSeries(wxString path, Config config) {
    constexpr size_t n = 61;
    wxImage img = gen.getOriginalImage();
    Kaleidoscope gen;
    // TODO: add to dialog width of images: gen.setSide(...);
    // TODO: add to dialog interpolator and drawAxis
    gen.setAxis(m_sliderAxis->GetValue());
    gen.setSide(img.GetWidth());
    gen.setImage(img.Copy());
    gen.setInterpolation(Kaleidoscope::InterpolationMethod(
        m_choiceInterpolator->GetSelection()));
    gen.setDrawAxis(m_checkBoxDrawAxis->GetValue());
    double dx = std::abs(config.dx2 / 100.0 - config.dx1 / 100.0) / (n - 1);
    double dy = std::abs(config.dy2 / 100.0 - config.dy1 / 100.0) / (n - 1);
    double dphi = std::abs(config.phi2 - config.phi1) / (n - 1);
    for (int i = 0; i < n; i++) {
        gen.setTranslateX(config.dx1 / 100.0 + dx * i);
        gen.setTranslateY(config.dy1 / 100.0 + dy * i);
        gen.setAngle(config.phi1 + dphi * i);
        gen.getImage().SaveFile(
            path + std::filesystem::path::preferred_separator +
                std::to_string(i) +
                " fi=" + std::to_string(config.phi1 + dphi * i) +
                " dx=" + std::to_string(config.dx1 + dx * i) +
                " dy=" + std::to_string(config.dy1 + dy * i) + ".png",
            wxBITMAP_TYPE_PNG);
        wxCommandEvent eventUpdate(wxEVT_COMMAND_BUTTON_CLICKED,
                                   ID_UPDATE_PROGRESS);
        eventUpdate.SetInt((i + 1) * 100 / n);
        wxQueueEvent(this, eventUpdate.Clone());
    }
}

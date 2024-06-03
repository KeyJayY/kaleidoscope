#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent) {
    wxInitAllImageHandlers();
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &GUIMyFrame1::OnThreadCompletion, this,
         windowId);
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &GUIMyFrame1::UpdateProgressBar, this,
         ID_UPDATE_PROGRESS);
    resizeTimer.Bind(wxEVT_TIMER, &GUIMyFrame1::onResizeTimer, this);
    this->SetDoubleBuffered(true);
}

void GUIMyFrame1::changeSize(wxSizeEvent& event) {
    resizeTimer.Start(100, wxTIMER_ONE_SHOT);
    event.Skip();
}

void GUIMyFrame1::drawOnPaint(wxPaintEvent& event) {
    wxPaintDC dc(m_panel1);
    dc.DrawBitmap(gen.getBitmap(), 0, 0, true);
}

void GUIMyFrame1::scrollChangeAxisNumber(wxScrollEvent& event) {
    axisNumberText->SetLabel(std::to_string(axis->GetValue()));
    gen.setAxis(axis->GetValue());
    if (auto_update) Repaint();
}

void GUIMyFrame1::scrollRotate(wxScrollEvent& event) {
    rotateText->SetLabel(std::to_string(rotate->GetValue()));
    gen.setAngle(rotate->GetValue());
    if (auto_update) Repaint();
}

void GUIMyFrame1::translateX(wxScrollEvent& event) {
    translationXText->SetLabel(std::to_string(translateXSlider->GetValue()));
    gen.setTranslateX(translateXSlider->GetValue() / 100.0);
    if (auto_update) Repaint();
}

void GUIMyFrame1::translateY(wxScrollEvent& event) {
    translationYText->SetLabel(std::to_string(translateYSlider->GetValue()));
    gen.setTranslateY(translateYSlider->GetValue() / 100.0);
    if (auto_update) Repaint();
}

void GUIMyFrame1::drawOnChange(wxCommandEvent& event) {
    auto_update = drawOnChangeCheckBox->GetValue();
    if (auto_update) Repaint();
}

void GUIMyFrame1::drawAxisChange(wxCommandEvent& event) {
    gen.setDrawAxis(drawAxisCheck->GetValue());
    if (auto_update) Repaint();
}

void GUIMyFrame1::changeInterpolator(wxCommandEvent& event) {
    gen.setInterpolation(
        Kaleidoscope::InterpolationMethod(interpolator->GetSelection()));
    if (auto_update) Repaint();
}

void GUIMyFrame1::loadImage(wxCommandEvent& event) {
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
        wxLogError("Nie można zapisać obrazu!");
    }
}

void GUIMyFrame1::clickDraw(wxCommandEvent& event) { Repaint(); }

void GUIMyFrame1::UpdateProgressBar(wxCommandEvent& event) {
    int progress = event.GetInt();
    if (dlg && dlg->progressBar) {
        dlg->progressBar->SetValue(progress);
    }
}

void GUIMyFrame1::generateSeries(wxString path, Config config) {
    constexpr size_t n = 61;
    Kaleidoscope gen;
    // TODO: add to dialog width of images: gen.setSide(...);
    // TODO: add to dialog interpolator and drawAxis
    gen.setInterpolation(
        Kaleidoscope::InterpolationMethod(interpolator->GetSelection()));
    gen.setDrawAxis(drawAxisCheck->GetValue());
    double dx = std::abs(config.dx2 - config.dx1) / (n - 1);
    double dy = std::abs(config.dy2 - config.dy1) / (n - 1);
    double dphi = std::abs(config.phi2 - config.phi1) / (n - 1);
    for (int i = 0; i < n; i++) {
        gen.setTranslateX(config.dx1 + dx * i);
        gen.setTranslateY(config.dy1 + dy * i);
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

void GUIMyFrame1::OnThreadCompletion(wxCommandEvent& event) {
    if (dlg) {
        dlg->EndModal(wxID_OK);
        dlg->Destroy();
        dlg = nullptr;
    }
}

void GUIMyFrame1::resetOptions() {
    gen.resetParameters();
    axis->SetValue(0);
    rotate->SetValue(0);
    translateXSlider->SetValue(0);
    translateYSlider->SetValue(0);
    axisNumberText->SetLabel("0");
    rotateText->SetLabel("0");
    translationXText->SetLabel("0");
    translationYText->SetLabel("0");
}

void GUIMyFrame1::onResizeTimer(wxTimerEvent& event) {
    gen.setSide(m_panel1->GetSize().x);
    Repaint();
}

bool GUIMyFrame1::ensureImageLoaded() {
    if (gen.isImageLoaded()) return false;
    wxMessageBox("Nie wczytano obrazu", "Nie wczytano obrazu",
                 wxOK | wxICON_ERROR);
    return true;
}

void GUIMyFrame1::Repaint() {
    if (!gen.isImageLoaded()) return;
    auto millis = gen.getLastUpdateMillis();
    auto timeText = std::format("{:.3} ms / {:.1f} FPS", millis, 1000 / millis);
    m_staticText20->SetLabelText(timeText);
    Refresh();
}

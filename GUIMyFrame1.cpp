#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent) {
    wxInitAllImageHandlers();
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &GUIMyFrame1::OnThreadCompletion, this,
         windowId);
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &GUIMyFrame1::UpdateProgressBar, this,
         ID_UPDATE_PROGRESS);
    resizeTimer.Bind(wxEVT_TIMER, &GUIMyFrame1::onResizeTimer, this);
}

void GUIMyFrame1::changeSize(wxSizeEvent& event) {
    toResize = true;
    resizeTimer.Start(100, wxTIMER_ONE_SHOT);
    event.Skip();
}

void GUIMyFrame1::drawOnPaint(wxPaintEvent& event) {
    if (imgResult.IsOk()) {
        wxClientDC dc(m_panel1);
        if (drawAxisBool) drawAxis();
        wxBitmap bitmap(imgResult);
        dc.DrawBitmap(bitmap, 0, 0, true);
    }
}

void GUIMyFrame1::scrollChangeAxisNumber(wxScrollEvent& event) {
    axisNumberText->SetLabel(std::to_string(axis->GetValue()));
    setAxis(axis->GetValue());
    if (onChange) Repaint();
}

void GUIMyFrame1::scrollRotate(wxScrollEvent& event) {
    rotateText->SetLabel(std::to_string(rotate->GetValue()));
    angle = rotate->GetValue();
    if (onChange) Repaint();
}

void GUIMyFrame1::translateX(wxScrollEvent& event) {
    translationXText->SetLabel(std::to_string(translateXSlider->GetValue()));
    translateX(translateXSlider->GetValue());
    translateY(translateYSlider->GetValue());
}

void GUIMyFrame1::translateY(wxScrollEvent& event) {
    translationYText->SetLabel(std::to_string(translateYSlider->GetValue()));
    translateX(translateXSlider->GetValue());
    translateY(translateYSlider->GetValue());
}

void GUIMyFrame1::drawOnChange(wxCommandEvent& event) {
    onChange = drawOnChangeCheckBox->GetValue();
}

void GUIMyFrame1::drawAxisChange(wxCommandEvent& event) {
    drawAxisBool = drawAxisCheck->GetValue();
    if (onChange) Repaint();
}

void GUIMyFrame1::changeInterpolator(wxCommandEvent& event) {
    linear = !interpolator->GetSelection();
    if (onChange) Repaint();
}

void GUIMyFrame1::loadImage(wxCommandEvent& event) {
    wxFileDialog openFileDialog(
        this, _("Wybierz obraz"), "", "",
        "Wszystkie pliki obrazów (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL) return;

    resetOptions();
    wxString imagePath = openFileDialog.GetPath();
    wxImage image(imagePath);
    imgOriginal = image.Copy();
    imgResized = image.Copy();
    img = image.Copy();
    imgResult = image.Copy();
    resizeImages();
    Repaint();
}

void GUIMyFrame1::clickSaveSeries(wxCommandEvent& event) {
    if (!img.IsOk()) {
        wxMessageBox("Nie wczytano obrazu", "Nie wczytano obrazu",
                     wxOK | wxICON_ERROR);
        return;
    }
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
    if (!img.IsOk()) {
        wxMessageBox("Nie wczytano obrazu", "Nie wczytano obrazu",
                     wxOK | wxICON_ERROR);
        return;
    }
    wxFileDialog saveFileDialog(
        this, _("Zapisz obraz jako..."), "", "",
        "Pliki JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg|Pliki PNG (*.png)|*.png",
        wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    wxString filePath = saveFileDialog.GetPath();

    wxBitmapType fileType = wxBITMAP_TYPE_ANY;
    if (filePath.EndsWith(".jpg") || filePath.EndsWith(".jpeg")) {
        fileType = wxBITMAP_TYPE_JPEG;
    } else if (filePath.EndsWith(".png")) {
        fileType = wxBITMAP_TYPE_PNG;
    }

    if (!imgResult.SaveFile(filePath, fileType)) {
        wxLogError("Nie można zapisać obrazu!");
    }
}

void GUIMyFrame1::clickDraw(wxCommandEvent& event) { Repaint(); }

void GUIMyFrame1::resetOptions() {
    setAxis(0);
    angle = 0;
    axis->SetValue(0);
    rotate->SetValue(0);
    translateXSlider->SetValue(0);
    translateYSlider->SetValue(0);
    axisNumberText->SetLabel("0");
    rotateText->SetLabel("0");
    translationXText->SetLabel("0");
    translationYText->SetLabel("0");
}

void GUIMyFrame1::Repaint() {
    auto t0 = std::chrono::high_resolution_clock::now();
    if (toResize) {
        resizeImages();
        translateX(translateXSlider->GetValue());
        translateY(translateYSlider->GetValue());
    }
    if (img.IsOk()) {
        imgResult = img.Copy();
        if (linear) {
            imgResult = RotateImageLinear(imgResult, angle);
            drawKaleidoscope();
            imgResult = RotateImageLinear(imgResult, -angle);
        } else {
            imgResult = RotateImageCubic(imgResult, angle);
            drawKaleidoscope();
            imgResult = RotateImageCubic(imgResult, -angle);
        }
        Refresh();
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t1 - t0;
    m_staticText20->SetLabelText(std::format("{:.3} ms / {:.1f} FPS",
                                             ms_double.count(),
                                             1000.0 / ms_double.count()));
}

void GUIMyFrame1::generateSeries(wxString path, Config config) {
    double oldAngle = angle;
    bool change = onChange;
    onChange = false;
    double dx = fabs(config.dx2 - config.dx1) / 60;
    double dy = fabs(config.dy2 - config.dy1) / 60;
    double dfi = fabs(config.fi2 - config.fi1) / 60;
    for (int i = 0; i <= 60; i++) {
        translateX(config.dx1 + dx * i);
        translateY(config.dy1 + dy * i);
        imgResult = img.Copy();
        angle = config.fi1 + dfi * i;
        if (linear) {
            imgResult = RotateImageLinear(imgResult, angle);
            drawKaleidoscope();
            imgResult = RotateImageLinear(imgResult, -angle);
        } else {
            imgResult = RotateImageCubic(imgResult, angle);
            drawKaleidoscope();
            imgResult = RotateImageCubic(imgResult, -angle);
        }
        if (drawAxisBool) drawAxis();
        imgResult.SaveFile(path + "\\" + std::to_string(i) +
                               " fi=" + std::to_string(config.fi1 + dfi * i) +
                               " dx=" + std::to_string(config.dx1 + dx * i) +
                               " dy=" + std::to_string(config.dy1 + dy * i) +
                               ".png",
                           wxBITMAP_TYPE_PNG);
        wxCommandEvent eventUpdate(wxEVT_COMMAND_BUTTON_CLICKED,
                                   ID_UPDATE_PROGRESS);
        eventUpdate.SetInt((i * 100) / 60);
        wxQueueEvent(this, eventUpdate.Clone());
    }
    angle = oldAngle;
    onChange = change;
}

void GUIMyFrame1::drawKaleidoscope() {
    wxPoint center = wxPoint(250, 250);
    for (auto phi : axisVect) {
        if (linear) {
            imgResult = RotateImageLinear(imgResult, phi);
            MirrorRightHalf(imgResult);
            imgResult = RotateImageLinear(imgResult, -phi);
        } else {
            imgResult = RotateImageCubic(imgResult, phi);
            MirrorRightHalf(imgResult);
            imgResult = RotateImageCubic(imgResult, -phi);
        }
    }
}

void GUIMyFrame1::resizeImages() {
    imgResized = imgOriginal.Copy();
    imgResized.Rescale(m_panel1->GetSize().x, m_panel1->GetSize().y,
                       wxIMAGE_QUALITY_HIGH);
    img = imgResized.Copy();
    imgResult = imgResized.Copy();
    toResize = false;
}

void GUIMyFrame1::translateX(double translation) {
    translation = -translation;
    img = imgResized.Copy();
    wxImage img1 = img.Copy();
    unsigned char* data1 = img1.GetData();
    unsigned char* resultData = img.GetData();
    int height = img.GetHeight();
    int width = img.GetWidth();

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index2;
            if (translation >= 0) {
                if (x < (int)(width - width * translation / 100))
                    index2 =
                        (y * width + x + (int)(width * translation / 100)) * 3;
                else {
                    index2 = (y * width +
                              (int)(width - width * translation / 100) - x) *
                             3;
                }
            } else {
                if (x > (int)(width - width * (100 + translation) / 100))
                    index2 = (y * width + x +
                              (int)(width * (100 + translation) / 100)) *
                             3;
                else {
                    index2 =
                        (y * width +
                         (int)(width - width * (100 + translation) / 100) - x) *
                        3;
                }
            }

            int index1 = (y * width + x) * 3;
            if (index2 < height * width * 3 && index2 >= 0) {
                resultData[index1] = data1[index2];
                resultData[index1 + 1] = data1[index2 + 1];
                resultData[index1 + 2] = data1[index2 + 2];
            }
        }
    }
}

void GUIMyFrame1::drawAxis() {
    double heigth = m_panel1->GetSize().x;
    wxBitmap bitmap(imgResult.GetWidth(), imgResult.GetHeight());
    wxMemoryDC dc;
    dc.SelectObject(bitmap);
    dc.DrawBitmap(imgResult, 0, 0, false);
    dc.SetPen(*wxBLACK_PEN);
    for (auto phi : axisVect) {
        phi = -phi - angle;
        dc.DrawLine(cos((phi + 90) / 360 * 2 * M_PI) * heigth + heigth / 2,
                    sin((phi + 90) / 360 * 2 * M_PI) * heigth + heigth / 2,
                    cos((phi - 90) / 360 * 2 * M_PI) * heigth + heigth / 2,
                    sin((phi - 90) / 360 * 2 * M_PI) * heigth + heigth / 2);
    }
    imgResult = bitmap.ConvertToImage();
}

wxImage GUIMyFrame1::RotateImageLinear(const wxImage& source,
                                       double angleDegrees) {
    const double angleRadians = wxDegToRad(angleDegrees);
    int width = source.GetWidth();
    int height = source.GetHeight();

    wxImage result(width, height);
    result.InitAlpha();

    unsigned char* srcData = source.GetData();
    unsigned char* dstData = result.GetData();

    int centerX = width / 2;
    int centerY = height / 2;

#pragma omp parallel for
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int srcX = int(cos(angleRadians) * (x - centerX) +
                           sin(angleRadians) * (y - centerY) + centerX);
            int srcY = int(-sin(angleRadians) * (x - centerX) +
                           cos(angleRadians) * (y - centerY) + centerY);
            if (srcX < 0) srcX = -srcX;
            if (srcY < 0) srcY = -srcY;
            if (srcX >= width) srcX = 2 * width - srcX - 1;
            if (srcY >= height) srcY = 2 * height - srcY - 1;

            int srcIndex = (srcY * width + srcX) * 3;
            int dstIndex = (y * width + x) * 3;

            dstData[dstIndex] = srcData[srcIndex];
            dstData[dstIndex + 1] = srcData[srcIndex + 1];
            dstData[dstIndex + 2] = srcData[srcIndex + 2];
        }
    }

    return result;
}

float GUIMyFrame1::cubicInterpolate(float p[4], float x) {
    return p[1] + 0.5 * x *
                      (p[2] - p[0] +
                       x * (2.0 * p[0] - 5.0 * p[1] + 4.0 * p[2] - p[3] +
                            x * (3.0 * (p[1] - p[2]) + p[3] - p[0])));
}

float GUIMyFrame1::bicubicInterpolate(float patch[4][4], float x, float y) {
    float arr[4];
    for (int i = 0; i < 4; i++) {
        arr[i] = cubicInterpolate(patch[i], x);
    }
    return cubicInterpolate(arr, y);
}

wxImage GUIMyFrame1::MirrorRightHalf(const wxImage& source) {
    const int width = source.GetWidth();
    const int height = source.GetHeight();
    wxImage result(source);

    unsigned char* srcData = source.GetData();
    unsigned char* resultData = result.GetData();

#pragma omp parallel for
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int srcX = width - 1 - x;
            int srcPos = (y * width + srcX) * 3;
            int dstPos = (y * width + x) * 3;

            resultData[dstPos] = srcData[srcPos];
            resultData[dstPos + 1] = srcData[srcPos + 1];
            resultData[dstPos + 2] = srcData[srcPos + 2];
        }
    }

    return result;
}

void GUIMyFrame1::setAxis(int number) {
    axisVect.clear();
    double phi = 180. / number;
    for (int i = 0; i < number; i++) axisVect.push_back(phi * i);
}

void GUIMyFrame1::OnThreadCompletion(wxCommandEvent& event) {
    if (dlg) {
        dlg->EndModal(wxID_OK);
        dlg->Destroy();
        dlg = nullptr;
    }
}

void GUIMyFrame1::translateY(double translation) {
    wxImage img1 = img.Copy();
    unsigned char* data1 = img1.GetData();
    unsigned char* resultData = img.GetData();
    int height = img1.GetHeight();
    int width = img1.GetWidth();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index2;
            if (translation >= 0) {
                if (y <= (int)(height - height * translation / 100))
                    index2 =
                        ((int)(height * translation / 100 + y) * width + x) * 3;
                else
                    index2 =
                        ((int)(2 * height - y - height * translation / 100) *
                             width +
                         x) *
                        3;
            } else {
                if (y > (int)(height - height * (100 + translation) / 100))
                    index2 =
                        ((int)(height * translation / 100 + y) * width + x) * 3;
                else
                    index2 = ((int)(height - y -
                                    height * (100 + translation) / 100) *
                                  width +
                              x) *
                             3;
            }

            int index1 = (y * width + x) * 3;
            if (index2 < height * width * 3 && index2 >= 0) {
                resultData[index1] = data1[index2];
                resultData[index1 + 1] = data1[index2 + 1];
                resultData[index1 + 2] = data1[index2 + 2];
            }
        }
    }
    for (int x = 0; x < width - 1; x++) {
        int index1 =
            ((int)(height - height * translation / 100) * width + x) * 3;
        if (translation < 0)
            index1 =
                ((int)(height - height * (100 + translation) / 100) * width +
                 x) *
                3;
        int index2 = ((height - 1) * width + x) * 3;
        if (index1 < height * width * 3 && index1 >= 0 &&
            index2 < height * width * 3 && index2 >= 0) {
            resultData[index1] = data1[index2];
            resultData[index1 + 1] = data1[index2 + 1];
            resultData[index1 + 2] = data1[index2 + 2];
        }
    }

    if (onChange) Repaint();
}

void GUIMyFrame1::UpdateProgressBar(wxCommandEvent& event) {
    int progress = event.GetInt();
    if (dlg && dlg->progressBar) {
        dlg->progressBar->SetValue(progress);
    }
}

void GUIMyFrame1::onResizeTimer(wxTimerEvent& event) { Repaint(); }

wxImage GUIMyFrame1::RotateImageCubic(const wxImage& source,
                                      double angleDegrees) {
    const double angleRadians = -wxDegToRad(angleDegrees);
    int width = source.GetWidth();
    int height = source.GetHeight();

    wxImage result(width, width);
    result.InitAlpha();

    unsigned char* srcData = source.GetData();
    unsigned char* dstData = result.GetData();

#pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double dx = (x - width / 2);
            double dy = (y - height / 2);
            double srcX =
                cos(angleRadians) * dx - sin(angleRadians) * dy + width / 2;
            double srcY =
                sin(angleRadians) * dx + cos(angleRadians) * dy + height / 2;

            int ix = (int)floor(srcX);
            int iy = (int)floor(srcY);
            float fx = srcX - ix;
            float fy = srcY - iy;

            if (ix < 1) ix = 1 - ix;
            if (ix >= width - 2) ix = 2 * (width - 2) - ix - 2;
            if (iy < 1) iy = 1 - iy;
            if (iy >= height - 2) iy = 2 * (height - 2) - iy - 2;

            float patch[3][4][4];
            for (int c = 0; c < 3; c++) {
                for (int j = -1; j <= 2; j++) {
                    for (int i = -1; i <= 2; i++) {
                        int pos = ((iy + j) * width + (ix + i)) * 3 + c;
                        patch[c][j + 1][i + 1] = srcData[pos];
                    }
                }
            }

            float red = bicubicInterpolate(patch[0], fx, fy);
            float green = bicubicInterpolate(patch[1], fx, fy);
            float blue = bicubicInterpolate(patch[2], fx, fy);

            int dstIndex = (y * width + x) * 3;
            dstData[dstIndex] = std::min(std::max(int(red), 0), 255);
            dstData[dstIndex + 1] = std::min(std::max(int(green), 0), 255);
            dstData[dstIndex + 2] = std::min(std::max(int(blue), 0), 255);
            result.SetAlpha(x, y, 255);
        }
    }

    return result;
}

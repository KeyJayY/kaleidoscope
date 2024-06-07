#include "GUIMyDialog1.h"

GUIMyDialog1::GUIMyDialog1(wxWindow* parent) : MyDialog1(parent) {}

void GUIMyDialog1::clickGenerate(wxCommandEvent& event) {
    if (checkConfig()) {
        isOk = true;
        Close();
    } else
        wxMessageBox("Niepoprawne dane.", "Niepoprawne dane",
                     wxOK | wxICON_ERROR);
}

bool GUIMyDialog1::checkConfig() {
    if (!(m_textCtrlTranslateX1->GetValue().ToDouble(&(config.dx1)) &&
          m_textCtrlTranslateX2->GetValue().ToDouble(&(config.dx2)) &&
          m_textCtrlTranslateY1->GetValue().ToDouble(&(config.dy1)) &&
          m_textCtrlTranslateY1->GetValue().ToDouble(&(config.dy1)) &&
          m_textCtrlAngle1->GetValue().ToDouble(&(config.phi1)) &&
          m_textCtrlAngle2->GetValue().ToDouble(&(config.phi2))))
        return false;
    if (config.dx1 < -100 || config.dx1 > 100) return false;
    if (config.dx2 < -100 || config.dx2 > 100) return false;
    if (config.dy1 < -100 || config.dy1 > 100) return false;
    if (config.dy2 < -100 || config.dy2 > 100) return false;
    if (config.phi1 < 0 || config.phi1 > 360) return false;
    if (config.phi2 < 0 || config.phi1 > 360) return false;
    return true;
}

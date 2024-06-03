#include "GUIMyDialog1.h"

GUIMyDialog1::GUIMyDialog1(wxWindow* parent) : MyDialog1(parent) {}

void GUIMyDialog1::generate(wxCommandEvent& event) {
    if (checkConfig()) {
        isOk = true;
        Close();
    } else
        wxMessageBox("Niepoprawne dane", "niepoprawne dane",
                     wxOK | wxICON_ERROR);
}

bool GUIMyDialog1::checkConfig() {
    if (!(dx1Box->GetValue().ToDouble(&(config.dx1)) &&
          dx2Box->GetValue().ToDouble(&(config.dx2)) &&
          dy1Box->GetValue().ToDouble(&(config.dy1)) &&
          dy1Box->GetValue().ToDouble(&(config.dy1)) &&
          fi1Box->GetValue().ToDouble(&(config.phi1)) &&
          fi2Box->GetValue().ToDouble(&(config.phi2))))
        return false;
    if (config.dx1 < -100 || config.dx1 > 100) return false;
    if (config.dx2 < -100 || config.dx2 > 100) return false;
    if (config.dy1 < -100 || config.dy1 > 100) return false;
    if (config.dy2 < -100 || config.dy2 > 100) return false;
    if (config.phi1 < 0 || config.phi1 > 360) return false;
    if (config.phi2 < 0 || config.phi1 > 360) return false;
    return true;
}

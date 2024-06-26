#ifndef __GUIMyDialog1__
#define __GUIMyDialog1__

/**
@file
Subclass of MyDialog1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include <wx/wx.h>

struct Config {
    double dx1, dx2, dy1, dy2, phi1, phi2;
};

/** Implementing MyDialog1 */
class GUIMyDialog1 : public MyDialog1 {
   protected:
    // Handlers for MyDialog1 events.
    void clickGenerate(wxCommandEvent& event);

   public:
    /** Constructor */
    GUIMyDialog1(wxWindow* parent);
    //// end generated class members
    Config config;
    bool isOk = false;
    bool checkConfig();
};

#endif  // __GUIMyDialog1__

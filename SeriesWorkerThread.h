#pragma once
#include <wx/wx.h>

class GUIMyFrame1;
class SeriesWorkerThread : public wxThread {
   public:
    SeriesWorkerThread(GUIMyFrame1* parent, const wxString& path, Config c)
        : wxThread(wxTHREAD_DETACHED),
          m_parent(parent),
          m_path(path),
          config(c) {}

    virtual wxThread::ExitCode Entry();

   private:
    GUIMyFrame1* m_parent;
    wxString m_path;
    Config config;
};

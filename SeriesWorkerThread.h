#include "GUIMyFrame1.h"

class SeriesWorkerThread : public wxThread {
   public:
    SeriesWorkerThread(GUIMyFrame1* parent, const wxString& path, Config c)
        : wxThread(wxTHREAD_DETACHED),
          m_parent(parent),
          m_path(path),
          config(c) {}

    virtual wxThread::ExitCode Entry() {
        m_parent->generateSeries(m_path, config);
        wxQueueEvent(m_parent, new wxCommandEvent(wxEVT_COMMAND_BUTTON_CLICKED,
                                                  m_parent->id));
        return (wxThread::ExitCode)0;
    }

   private:
    GUIMyFrame1* m_parent;
    wxString m_path;
    Config config;
};

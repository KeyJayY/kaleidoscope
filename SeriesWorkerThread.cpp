#include "GUIMyFrame1.h"

wxThread::ExitCode SeriesWorkerThread::Entry() {
    m_parent->generateSeries(m_path, config);
    wxQueueEvent(m_parent, new wxCommandEvent(wxEVT_COMMAND_BUTTON_CLICKED,
                                              m_parent->ID_WINDOW));
    return (wxThread::ExitCode)0;
}

// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include "chessApp.hpp"
#include "frame.hpp"
#include "panel.hpp"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello, MyFrame::OnHello)
        EVT_MENU(wxID_EXIT, MyFrame::OnExit)
            EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
                wxEND_EVENT_TABLE()
                    wxBEGIN_EVENT_TABLE(Panel, wxPanel)
                        EVT_MOUSE_EVENTS(Panel::onMove)
                            wxEND_EVENT_TABLE()
                                wxIMPLEMENT_APP(ChessApp);

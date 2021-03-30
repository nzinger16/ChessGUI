#pragma once
#include "commonGUI.hpp"

class Panel : public wxPanel
{
public:
    Panel(wxFrame *parent);

    // private:
    void createBoardGUI(wxPaintEvent &event);
    void drawSquare(wxPaintDC &dc, int x, int y);
    int Panel::SquareLength();
};
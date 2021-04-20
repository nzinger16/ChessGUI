#pragma once
#include "commonGUI.hpp"
#include "board.hpp"

class Panel : public wxPanel
{
public:
    Panel(wxFrame *parent);

    // private:
    void createBoardGUI(wxPaintEvent &event);
    void onMouseDown(wxMouseEvent &event);
    void onMouseUp(wxMouseEvent &event);
    void onMove(wxMouseEvent &event);
    void drawSquare(wxPaintDC &dc, int x, int y);
    bool checkPosition(Piece &p, wxPoint &pt);
    bool Panel::isValidMove(int xPos, int yPos, Piece *p);
    void performDrag(Piece *p, wxMouseEvent &event);
    int Panel::SquareLength();
    Board *board;
    bool initImageHandler;
    wxDragImage *pieceDrag;

private:
    wxDECLARE_EVENT_TABLE();
    // int pieceSize;
};
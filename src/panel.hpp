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
    // void drawSquare(wxPaintDC &dc, int x, int y);
    void drawSquare(int x, int y);
    bool checkPosition(Piece &p, wxPoint &pt);
    void performDrag(Piece *p, wxMouseEvent &event);
    void removePiece(Piece *p);
    int Panel::SquareLength();
    Board *board;
    wxDragImage *pieceDrag;
    wxPaintDC *dc;

private:
    wxDECLARE_EVENT_TABLE();
    // int pieceSize;
};
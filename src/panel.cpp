#include "panel.hpp"
#include "board.hpp"

Panel::Panel(wxFrame *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE)
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(Panel::createBoardGUI));
}

void Panel::createBoardGUI(wxPaintEvent &event)
{
    //Draw board squares
    wxPaintDC dc(this);
    for (int i = 0; i < boardLength; i++)
    {
        for (int j = 0; j < boardLength; j++)
        {
            drawSquare(dc, i, j);
        }
    }

    //Add Chess Nomenclature

    // Create Board and add chess pieces
    Board board;
    board.initialize();
    ::wxInitAllImageHandlers();
    int squareLength = SquareLength();
    for (int i = 0; i < boardLength; i++)
    {
        for (int j = 0; j < boardLength; j++)
        {
            Piece p = board.ChessBoard[i][j];
            if (!p.isEmpty)
            {
                auto pieceGuiString = p.colour ? chessImagesWhite[p.type] : chessImagesBlack[p.type];
                auto pieceGuiImage = wxImage(pieceGuiString);
                dc.DrawBitmap(wxBitmap(pieceGuiImage.Scale(squareLength, squareLength)), j * squareLength, i * squareLength, false);
            }
        }
    }
}

void Panel::drawSquare(wxPaintDC &dc, int x, int y)
{
    static wxColor light = wxColor(255, 222, 173);
    static wxColor dark = wxColor(205, 133, 63);

    dc.SetPen(*wxTRANSPARENT_PEN);
    if (x % 2 == y % 2)
    {
        dc.SetBrush(wxBrush(light));
    }
    else
    {
        dc.SetBrush(wxBrush(dark));
    }
    dc.DrawRectangle(x * SquareLength(), y * SquareLength(),
                     SquareLength(), SquareLength());
}

int Panel::SquareLength()
{
    int width = GetClientSize().GetWidth();
    int height = GetClientSize().GetHeight();
    int length = std::min(width, height) / boardLength;
    return length;
}
#include "panel.hpp"

Panel::Panel(wxFrame *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE)
{
    board = new Board();
    board->initialize();
    pieceDrag = (wxDragImage *)NULL;
    // pieceSize = SquareLength();
    Connect(wxEVT_PAINT, wxPaintEventHandler(Panel::createBoardGUI));
    Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(Panel::onMouseDown));
    Connect(wxEVT_LEFT_UP, wxMouseEventHandler(Panel::onMouseUp));
    // Connect(wxEVT_MOTION, wxMouseEventHandler(Panel::onMove));
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
    // Board board;
    // board.initialize();
    ::wxInitAllImageHandlers();
    int pieceSize = SquareLength();
    for (int i = 0; i < boardLength; i++)
    {
        for (int j = 0; j < boardLength; j++)
        {
            Piece *p = &(board->ChessBoard[i][j]);
            if (!p->isEmpty)
            {
                auto pieceGuiString = p->colour ? chessImagesWhite[p->type] : chessImagesBlack[p->type];
                auto pieceGuiImage = wxImage(pieceGuiString);
                p->boardX = j * pieceSize;
                p->boardY = i * pieceSize;
                p->pieceSize = pieceSize;
                p->pieceImage = wxBitmap(pieceGuiImage.Scale(pieceSize, pieceSize));
                dc.DrawBitmap(p->pieceImage, j * pieceSize, i * pieceSize, false);
            }
        }
    }

    // for (int i = 0; i < boardLength; i++)
    // {
    //     for (int j = 0; j < boardLength; j++)
    //     {
    //         auto p = board->ChessBoard[i][j];
    //         if (!p.isEmpty)
    //             log(p.pieceName, p.boardX, p.boardY);
    //     }
    // }
}

void Panel::onMouseDown(wxMouseEvent &event)
{
    //Get click position
    auto pos = event.GetPosition();

    for (int i = 0; i < boardLength; i++)
    {
        for (int j = 0; j < boardLength; j++)
        {
            auto *p = &(board->ChessBoard[i][j]);
            if (!p->isEmpty)
            {
                //Check if click position is on a chess Piece
                if (checkPosition(*p, pos))
                {
                    log("clicked on a chess piece!!");
                    p->isClicked = true;
                    p->clickPos = pos;
                }
                // dragImage(p->pieceImage);
                // wxDragImage dragImage(p->pieceImage);
            }
        }
    }
}

bool Panel::checkPosition(Piece &p, wxPoint &pt)
{
    wxRect rect(p.boardX, p.boardY, p.pieceImage.GetWidth(), p.pieceImage.GetHeight());
    return rect.Contains(pt.x, pt.y);
}

void Panel::onMove(wxMouseEvent &event)
{
    // log("Got in here!! onMove()");
    //future, templated lambda function to parse board then -> do something with piece/pieces
    // bool draggingBegun = false;
    for (int i = 0; i < boardLength; i++)
    {
        for (int j = 0; j < boardLength; j++)
        {
            auto *p = &(board->ChessBoard[i][j]);
            if (!p->isEmpty && p->isClicked && event.Dragging())
            {
                performDrag(p, event);
            }
        }
    }
}

void Panel::performDrag(Piece *p, wxMouseEvent &event)
{
    if (!p->isDragging)
    {
        if (pieceDrag)
        {
            delete pieceDrag;
        }
        pieceDrag = new wxDragImage(p->pieceImage, wxCursor(wxCURSOR_HAND));
        pieceDrag->BeginDrag(wxPoint(0, 0), this);
        p->isDragging = true;
    }
    else
    {
        p->isDragging = true;
        pieceDrag->Move(event.GetPosition());
        pieceDrag->Show();
    }
}
void Panel::onMouseUp(wxMouseEvent &event)
{
    for (int i = 0; i < boardLength; i++)
    {
        for (int j = 0; j < boardLength; j++)
        {
            auto *p = &(board->ChessBoard[i][j]);
            if (!p->isEmpty && p->isDragging)
            {
                // delete pieceDrag;
                pieceDrag->EndDrag();
                wxDELETE(pieceDrag);
                p->isClicked = false;
                p->isDragging = false;
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
#pragma once
#include "commonGui.hpp"
#include <string>
class Piece
{
public:
    //piece coordinates on board
    int x;
    int y;
    //Empty spot on the board
    bool isEmpty;
    PieceType type;
    std::string coordName;
    //true = white, false = black
    bool colour;

    bool isLoaded; //Piece was already loaded onto the board

    // GUI variables for moving pieces
    int pieceSize;
    int boardX;
    int boardY;
    wxBitmap pieceImage;
    bool isDragging;
    bool isClicked;
    wxPoint dragPos;
    wxPoint clickPos;

    std::string pieceName;

    Piece()
    {
        isEmpty = true;
    }

    void setPieceName();

    Piece(PieceType type, bool colour) : type(type), colour(colour), isEmpty(false), isDragging(false), isClicked(false), isLoaded(false)
    {
        setPieceName();
    }
};
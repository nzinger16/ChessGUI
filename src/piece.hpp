#pragma once
#include "commonGui.hpp"
#include <string>
class Piece
{
public:
    //piece coordinates on board
    // int x;
    // int y;
    //Empty spot on the board
    bool isEmpty;
    PieceType type;
    std::string coordName;
    //true = white, false = black
    bool colour;

    // GUI variables for moving pieces
    int pieceSize;
    int boardX;
    int boardY;
    wxBitmap pieceImage;
    bool isDragging;
    bool isClicked;
    wxPoint dragPos;
    wxPoint clickPos;

    //potentially use OOP inheritence for each individual piece?
    bool hasMoved;
    std::string pieceName;

    Piece()
    {
        isEmpty = true;
    }

    void setPieceName();
    //Need original x and y coordinates + new x and y coordinates of user piece placement
    bool isValidPieceMove(int origX, int origY, int newX, int newY);
    bool isPawnMoveValid(int origX, int origY, int newX, int newY);

    Piece(PieceType type, bool colour) : type(type), colour(colour), isEmpty(false), isDragging(false), isClicked(false), hasMoved(false)
    {
        setPieceName();
    }
};
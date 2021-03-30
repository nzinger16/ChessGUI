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
    // wxImage img;

    Piece()
    {
        isEmpty = true;
    }
    Piece(PieceType type, bool colour) : type(type), colour(colour), isEmpty(false)
    {
    }
};
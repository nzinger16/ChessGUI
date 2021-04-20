#include "piece.hpp"

void Piece::setPieceName()
{
    switch (type)
    {
    case Pawn:
        pieceName = "Pawn";
        break;
    case Bishop:
        pieceName = "Bishop";
        break;
    case Knight:
        pieceName = "Knight";
        break;
    case Rook:
        pieceName = "Rook";
        break;
    case Queen:
        pieceName = "Queen";
        break;
    case King:
        pieceName = "King";
        break;
    }
}

bool Piece::isValidPieceMove(int origX, int origY, int newX, int newY)
{
    //first check if piece moved at all
    if ((origX == newX) && (origY == newY))
    {
        return false;
    }

    bool valid = true;

    switch (type)
    {
    case Pawn:
        valid = isPawnMoveValid(origX, origY, newX, newY) ? valid : false;
    default:
        break;
    }
    return valid;
}

bool Piece::isPawnMoveValid(int origX, int origY, int newX, int newY)
{
    //Pawn can't move sideways... for now, will add param for when captures are supported
    if (origX != newX)
    {
        return false;
    }

    //different for white vs black pawn pieces
    if (colour)
    { //white pawns
        if (hasMoved)
        {
            if (origY - newY != 1)
            {
                return false;
            }
        }
        else
        {
            if (origY - newY > 2)
            {
                return false;
            }
        }
    }
    else //black pawns
    {
        if (hasMoved)
        {
            if (newY - origY != 1)
            {
                return false;
            }
        }
        else
        {
            if (newY - origY > 2)
            {
                return false;
            }
        }
    }

    return true;
}
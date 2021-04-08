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
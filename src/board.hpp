#pragma once
#include "piece.hpp"
#include <array>
class Board
{
public:
    void initialize();
    bool hasPieceAtPosition(int i, int j);
    Piece ChessBoard[boardLength][boardLength];
};
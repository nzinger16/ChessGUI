#pragma once
#include "piece.hpp"
#include <array>
class Board
{
public:
    void initialize();
    Piece ChessBoard[boardLength][boardLength];
};
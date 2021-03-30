#include "board.hpp"

void Board::initialize()
{
    //Black Pieces:
    ChessBoard[0][0] = Piece(Rook, false);

    ChessBoard[0][1] = Piece(Knight, false);
    ChessBoard[0][2] = Piece(Bishop, false);
    ChessBoard[0][3] = Piece(Queen, false);
    ChessBoard[0][4] = Piece(King, false);
    ChessBoard[0][5] = Piece(Bishop, false);
    ChessBoard[0][6] = Piece(Knight, false);
    ChessBoard[0][7] = Piece(Rook, false);
    ChessBoard[1][0] = Piece(Pawn, false);
    ChessBoard[1][1] = Piece(Pawn, false);
    ChessBoard[1][2] = Piece(Pawn, false);
    ChessBoard[1][3] = Piece(Pawn, false);
    ChessBoard[1][4] = Piece(Pawn, false);
    ChessBoard[1][5] = Piece(Pawn, false);
    ChessBoard[1][6] = Piece(Pawn, false);
    ChessBoard[1][7] = Piece(Pawn, false);

    //Fill in the rest with empty pieces
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ChessBoard[i][j] = Piece();
        }
    }

    //White Pieces
    ChessBoard[6][0] = Piece(Pawn, true);
    ChessBoard[6][1] = Piece(Pawn, true);
    ChessBoard[6][2] = Piece(Pawn, true);
    ChessBoard[6][3] = Piece(Pawn, true);
    ChessBoard[6][4] = Piece(Pawn, true);
    ChessBoard[6][5] = Piece(Pawn, true);
    ChessBoard[6][6] = Piece(Pawn, true);
    ChessBoard[6][7] = Piece(Pawn, true);
    ChessBoard[7][0] = Piece(Rook, true);
    ChessBoard[7][1] = Piece(Knight, true);
    ChessBoard[7][2] = Piece(Bishop, true);
    ChessBoard[7][3] = Piece(Queen, true);
    ChessBoard[7][4] = Piece(King, true);
    ChessBoard[7][5] = Piece(Bishop, true);
    ChessBoard[7][6] = Piece(Knight, true);
    ChessBoard[7][7] = Piece(Rook, true);

    return;
}
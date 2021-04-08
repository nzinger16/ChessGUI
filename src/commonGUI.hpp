#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "wx/generic/dragimgg.h"
#define wxDragImage wxGenericDragImage

#include <map>

enum
{
    ID_Hello = 1
};

constexpr int boardLength = 8;

enum PieceType
{
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King
};

namespace
{
    // ::wxInitAllImageHandlers();
    std::map<PieceType, wxString> chessImagesWhite = {
        {Pawn, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\white_pawn.png"))},
        {Bishop, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\white_bishop.png"))},
        {Knight, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\white_knight.png"))},
        {Rook, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\white_rook.png"))},
        {Queen, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\white_queen.png"))},
        {King, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\white_king.png"))}};
    std::map<PieceType, wxString> chessImagesBlack = {
        {Pawn, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\black_pawn.png"))},
        {Bishop, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\black_bishop.png"))},
        {Knight, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\black_knight.png"))},
        {Rook, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\black_rook.png"))},
        {Queen, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\black_queen.png"))},
        {King, wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\black_king.png"))}};

    //Logging
    void log()
    {
        std::cout << std::endl;
    }
    template <typename T, typename... Types>
    void log(T var, Types... varsToPrint)
    {
        std::cout << var << " ";
        log(varsToPrint...);
    }
}
// chessImagesWhite[Pawn] = wxString(wxT("C:\\Projects\\chess_app_gui\\src\\img\\black_king.png");

#include "chessApp.hpp"
#include "frame.hpp"

bool ChessApp::OnInit()
{
    MyFrame *frame = new MyFrame("CHESS", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
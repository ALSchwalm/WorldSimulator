
#include "Interface/CLI/Dialog/DialogOK.h"
#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"

using namespace Interface::CLI;

DialogOK::DialogOK(std::string displayText) :
    Dialog(subwin(mainwin, 3, displayText.size()+4, LINES/2, COLS/2-(displayText.size()/2))),
    text(displayText)
{
    mvwprintw(dialogWin, 0, 2, "Error");
    mvwprintw(dialogWin, 1, 1, displayText.c_str());
    wrefresh(mainwin);
}

void DialogOK::handleInput()
{
    box(dialogWin, 0, 0);
    mvwprintw(dialogWin, 0, 2, "Error");
    mvwprintw(dialogWin, 1, 1, text.c_str());
    wrefresh(mainwin);
    char c = wgetch(dialogWin);
    if (c == 10)
    {
        wclear(dialogWin);
        wrefresh(dialogWin);
        dialogs.pop_back();
    }
}


#include "Interface/CLI/Dialog/DialogOK.h"
#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"

using namespace Interface::CLI;

DialogOK::DialogOK(std::string displayText) :
		Dialog(subwin(mainwin, 4, 10, LINES/2, COLS/2))
{
	mvwprintw(dialogWin, 0, 2, "Error");
	mvwprintw(dialogWin, 1, 1, displayText.c_str());
	wrefresh(dialogWin);
}

void DialogOK::handleInput()
{
	char c = wgetch(dialogWin);
	if (c == 10)
	{
		wclear(dialogWin);
		wrefresh(dialogWin);
		dialogs.pop_back();

	}
}


#include "Interface/CLI/HelpView.h"

using namespace Interface;

HelpView::HelpView(std::vector<CLI::Command> completions) :
		commands(completions)
{
	this->viewWin = subwin(mainwin, LINES-3, COLS, 3, 0);
	wclear(viewWin);
	box(this->viewWin, 0, 0);

	mvwprintw(this->viewWin, 0, 2, "Help");

	refresh();
};

HelpView::~HelpView()
{
	//If this help view is being replaced with another, do not redraw display
	if (helpView == nullptr)
		displayView->redrawView(); //otherwise, redraw the display to correct the title
}

void HelpView::refreshView()
{
	//Display a header for columns
	mvwprintw(this->viewWin, 2, 4, "Command:\t\tHelp:");

	unsigned int counter = 4;
	for( auto command : commands)
	{
		mvwprintw(this->viewWin, counter, 4, command.getCommand().c_str());
		mvwprintw(this->viewWin, counter, 4+command.getCommand().size(), ("\t\t" + command.getHelp()).c_str());
		++counter;
	}
	wrefresh(this->viewWin);
};

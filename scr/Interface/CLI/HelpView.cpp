
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

    unsigned int longestCommand = 0;
    for (auto command : commands) {
        if (command.getCommand().size() > longestCommand)
            longestCommand = command.getCommand().size();
    }



    //The "Commands:" title is 8 characters long, this ensures there are always 4 spaces after it
    if (longestCommand < 8)
        longestCommand = 8;

    unsigned int counter = 4;
    for( auto command : commands)
    {
        mvwprintw(this->viewWin, counter, 4, command.getCommand().c_str());
        mvwprintw(this->viewWin, counter, longestCommand+8, command.getHelp().c_str());
        ++counter;
    }

    //Display a header for columns
    mvwprintw(this->viewWin, 2, 4, "Command:");
    mvwprintw(this->viewWin, 2, longestCommand+8, "Help:");

    wrefresh(this->viewWin);
};

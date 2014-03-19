
#include "Interface/CLI/HelpView.h"

using namespace Interface;

HelpView::HelpView(std::vector<CLI::Command> completions) :
        commands(completions)
{
    /*
     * Help panes are split 1/3 - 2/3 to better accommodate they typical
     * distribution of text.
     */
    this->titleWin = subwin(mainwin, LINES-3, COLS, 3, 0);
    this->nameWin = subwin(titleWin, LINES-5, (COLS-2)/3, 4, 1);
    this->dataWin = subwin(titleWin, LINES-5, 2*(COLS-2)/3, 4, COLS/3+1);
    wclear(titleWin);

    box(this->titleWin, 0, 0);
    mvwprintw(this->titleWin, 0, 2, "Help");

    wrefresh(this->titleWin);
};

HelpView::~HelpView()
{
    //If this help view is being replaced with another, do not redraw display
    if (helpView == nullptr)
        displayView->redrawView(); //otherwise, redraw the display to correct the title
}

void HelpView::refreshView()
{
    unsigned int counter = 4;
    for( auto command : commands)
    {
        mvwprintw(this->nameWin, counter, 4, command.getCommand().c_str());
        mvwprintw(this->dataWin, counter, 4, command.getHelp().c_str());
        ++counter;
    }

    //Display a header for columns
    mvwprintw(this->nameWin, 2, 4, "Command:");
    mvwprintw(this->dataWin, 2, 4, "Help:");

    wrefresh(this->dataWin);
    wrefresh(this->nameWin);
};

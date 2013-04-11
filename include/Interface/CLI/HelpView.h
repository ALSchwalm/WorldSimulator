#ifndef HELPVIEW_H_
#define HELPVIEW_H_

#include <memory>
#include <vector>
#include "Interface/View.h"
#include "Utils/curses.h"
#include "Utils/panel.h"
#include "Interface/CLI/Commands.h"

namespace Interface
{
	class HelpView : public BaseView
	{
	public:
		HelpView(std::vector<CLI::Command>);
		~HelpView();
		void redrawView(){};
		void refreshView();
	private:
		WINDOW * viewWin;
		std::shared_ptr<BaseView> previousView; //view to return to when the help is closed
		std::vector<CLI::Command> commands;
	};

	HelpView::HelpView(std::vector<CLI::Command> completions) :
			commands(completions)
	{
		previousView = displayView;
		this->viewWin = subwin(mainwin, LINES-3, COLS, 3, 0);
		wclear(viewWin);
		box(this->viewWin, 0, 0);

		mvwprintw(this->viewWin, 0, 2, "Help");

		refresh();
	};

	HelpView::~HelpView()
	{
		displayView = previousView;
		displayView->redrawView();

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



}
#endif

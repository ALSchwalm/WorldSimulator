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
	class HelpView : public View<std::vector<CLI::Command> >
	{
	public:
		HelpView(std::vector<CLI::Command>);

		void refreshView();

	};

	HelpView::HelpView(std::vector<CLI::Command> completions) :
		View<std::vector<CLI::Command>>(completions, "Help")
	{

	};

	void HelpView::refreshView()
	{
		//Display a header for columns
		mvwprintw(this->viewWin, 2, 4, "Command:\t\tHelp:");

		unsigned int counter = 4;
		for( auto command : this->viewSubject)
		{
			mvwprintw(this->viewWin, counter, 4, command.getCommand().c_str());
			mvwprintw(this->viewWin, counter, 4+command.getCommand().size(), ("\t\t" + command.getHelp()).c_str());
			++counter;
		}
		wrefresh(this->viewWin);
	};


}
#endif

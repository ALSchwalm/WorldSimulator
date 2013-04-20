#ifndef HELPVIEW_H_
#define HELPVIEW_H_

#include <vector>
#include "Interface/View.h"
#include "Utils/curses.h"
#include "Interface/CLI/Commands.h"

namespace Interface
{
	/*
	 * HelpView is a special case of view. It is not derived from View<T>,
	 * and it is not held in Interface::displayView. Instead, it has its own
	 * Interface::helpView variable. When a helpView is destroyed, it will
	 * either call a redraw of the displayView, or, if it is being replaced
	 * with another help view, it will do nothing.
	 */

	class HelpView : public BaseView
	{
	public:
		HelpView(std::vector<CLI::Command>);
		~HelpView();
		void redrawView(){};
		void refreshView() override;
	private:
		WINDOW * viewWin;
		std::vector<CLI::Command> commands;
	};
}
#endif
#ifndef INTERFACE_H_
#define INTERFACE_H_

#if _WIN32
# include "Utils/curses.h"
#elif __linux__
# include <ncurses.h>
#endif

#include "Interface/CLI/Context.h"
#include <memory>

namespace Interface
{
	class BaseView;

	void initialize();
	void refreshView();

	extern WINDOW * mainwin;
	extern std::shared_ptr<BaseView> displayView;
	extern std::shared_ptr<BaseView> helpView;
	extern CLI::Context currentContext;
}
#endif

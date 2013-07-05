#ifndef CLI_H_
#define CLI_H_

#if _WIN32
# include "Utils/curses.h"
#elif __linux__
# include <ncurses.h>
#endif

#include "Interface/Interface.h"
#include "Interface/CLI/Dialog/Dialog.h"
#include <vector>

namespace Interface
{
	namespace CLI
	{
		class Command;

		void initialize();
		extern WINDOW* CLIwin;
		extern WINDOW*	lineWin;
		extern std::vector<Dialog_ptr> dialogs;
		extern Command currentCommand;
		void handleInput();
	}
}

#endif

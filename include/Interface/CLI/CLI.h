#ifndef CLI_H_
#define CLI_H_

#include "Interface/Interface.h"
#include "Utils/curses.h"
#include "Interface/CLI/Dialog/Dialog.h"
#include <vector>

namespace Interface
{
	namespace CLI
	{

		void initialize();
		extern WINDOW * CLIwin;
		extern std::vector<Dialog_ptr> dialogs;
		void handleInput();
	}
}

#endif

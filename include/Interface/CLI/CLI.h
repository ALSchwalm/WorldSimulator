#ifndef CLI_H_
#define CLI_H_

#include "Interface/Interface.h"
#include "Utils/curses.h"

namespace Interface
{
	namespace CLI
	{

		void initialize();
		extern WINDOW * CLIwin;
		void handleInput();

	}
}

#endif

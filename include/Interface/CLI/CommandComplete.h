#ifndef COMMANDCOMPLETE_H_
#define COMMANDCOMPLETE_H_

#include "Interface/Interface.h"
#include "Interface/CLI/Commands.h"
#include "Utils/curses.h"
#include <string>
#include <vector>

namespace Interface
{
	namespace CLI
	{

		bool isCompletion(std::string input, std::string completion);
		std::vector<Command> getPossibleCompletions(std::string input);
		void showHelp(std::string input);
	}
}

#endif

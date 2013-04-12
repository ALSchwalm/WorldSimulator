#ifndef COMMANDCOMPLETE_H_
#define COMMANDCOMPLETE_H_

#include "Interface/Interface.h"
#include "Interface/CLI/Commands.h"
#include "Interface/CLI/Token.h"
#include "Utils/curses.h"
#include <string>
#include <vector>

namespace Interface
{
	namespace CLI
	{

		bool isCompletion(std::vector<Token> input, std::vector<Token> completion);
		const std::vector<Command> getPossibleCompletions(std::string input);
		const std::string cliCompleteCommand(std::string);
		void callCommand(std::string);
		void showHelp(std::string input);
		void closeHelp();
	}
}

#endif

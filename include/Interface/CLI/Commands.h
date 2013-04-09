#ifndef COMMAND_H_
#define COMMAND_H_

#include <functional>
#include <string>
#include <vector>
#include <iostream>

#include "Interface/CLI/Token.h"

namespace Interface
{
	namespace CLI
	{
		class Command
		{
		public:
			Command(std::string _commandString, bool (*_fn)(), std::string _helpString);

			std::string getCommand() {return commandString;}
			std::string getHelp() {return helpString;}
			const std::vector<Token> & getTokens(){return tokens;}
			void operator()();

		private:
			bool (*fn)();
			std::string commandString;
			std::string helpString;
			std::vector<Token> tokens;
		};

		inline bool NO_CALL()
		{
			return false;
		}

		const std::vector<Command> Commands = {
				Command("show", NO_CALL, "Change current view"),
				Command("show world", NO_CALL, "shows the world") ,
				Command("show test", NO_CALL, "shows a test")
		};

	}
}
#endif

#ifndef COMMAND_H_
#define COMMAND_H_

#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> //TODO remove this

#include "Interface/CLI/CLI.h"
#include "Interface/CLI/Token.h"
#include "Interface/CLI/Context.h"

namespace Interface
{
	namespace CLI
	{
		class Command
		{
		public:
			Command(std::string _commandString, bool (*_fn)(), std::string _helpString, Context);

			const std::string getCommand() {return commandString;}
			const std::string getHelp() {return helpString;}
			const std::vector<Token> & getTokens(){return tokens;}
			void operator()();

		private:
			bool (*fn)();
			std::string commandString;
			std::string helpString;
			std::vector<Token> tokens;
			Context context;
		};

		inline bool NO_CALL()
		{
			return false;
		}


		inline bool cliExit()
		{
			exit(0);
			return false;
		}

		const std::vector<Command> Commands = {
				Command("show", NO_CALL, "Change current view", Context::ALL),
				Command("show world", NO_CALL, "shows the world", Context::ALL),
				Command("exit", cliExit, "exit the simulation", Context::ALL)
		};

	}
}
#endif

#ifndef COMMAND_H_
#define COMMAND_H_

#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> //TODO remove this

#include "Interface/CLI/CLI.h"
#include "Interface/CLI/Token.h"
#include "Interface/CLI/Dialog/DialogOK.h" //TODO remove this

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

		inline bool MakeDialog()
		{
			dialogs.push_back(std::make_shared<DialogOK>("test"));

			return true;
		}

		inline bool cliExit()
		{
			exit(0);
			return true;
		}

		const std::vector<Command> Commands = {
				Command("show", NO_CALL, "Change current view"),
				Command("show world", NO_CALL, "shows the world"),
				Command("show test", MakeDialog, "shows a test"),
				Command("exit", cliExit, "exit the simulation")
		};

	}
}
#endif

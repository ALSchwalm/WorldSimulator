#ifndef COMMAND_H_
#define COMMAND_H_

#include <functional>
#include <string>
#include <vector>

namespace Interface
{
	namespace CLI
	{
		class Command
		{
		public:
			Command(std::string _commandString, bool (*_fn)(), std::string _helpString) :
				fn(_fn),
				commandString(_commandString),
				helpString(_helpString){}

			std::string getCommand() {return commandString;}
			std::string getHelp() {return helpString;}
			void operator()() {fn();}

		private:
			bool (*fn)();
			std::string commandString;
			std::string helpString;
		};

		inline bool F()
		{
			return true;
		}

		const std::vector<Command> Commands = {
				Command("show world", F, "shows the world"),
				Command("show test", F, "shows a test")
		};


	}
}
#endif

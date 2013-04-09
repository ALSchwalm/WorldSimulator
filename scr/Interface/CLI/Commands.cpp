
#include "Interface/CLI/Commands.h"

namespace Interface
{
	namespace CLI
	{
		Command::Command(std::string _commandString, bool (*_fn)(), std::string _helpString) :
			fn(_fn),
			commandString(_commandString),
			helpString(_helpString),
			tokens(Token::tokenize(commandString))
		{

		}

		void Command::operator()() {
			if(!fn())
			{
				std::cerr << "Invalid or incomplete command" << std::endl;
			}
		}


	}
}

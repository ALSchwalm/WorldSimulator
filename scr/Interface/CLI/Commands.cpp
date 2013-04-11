
#include "Interface/CLI/Commands.h"
#include "Interface/CLI/Dialog/DialogOK.h" //TODO remove this
#include "Interface/Interface.h"

namespace Interface
{
	namespace CLI
	{
		Command::Command(std::string _commandString, bool (*_fn)(), std::string _helpString, Context _context) :
			fn(_fn),
			commandString(_commandString),
			helpString(_helpString),
			tokens(Token::tokenize(commandString)),
			context(_context)
		{

		}

		void Command::operator()() {
			if (currentContext != context && context != Context::ALL)
			{
				dialogs.push_back(std::make_shared<DialogOK>("Invalid command within this context."));
				return;
			}

			if(!fn())
			{
				dialogs.push_back(std::make_shared<DialogOK>("Command failed."));
			}
		}


	}
}


#include "Interface/CLI/Commands.h"
#include "Interface/CLI/Dialog/DialogOK.h"
#include "Interface/Interface.h"

namespace Interface
{
    namespace CLI
    {
        Command::Command(std::string _commandString,
                bool (*_fn)(),
                std::string _helpString,
                Context _preContext,
                Context _postContext) :
            fn(_fn),
            commandString(_commandString),
            helpString(_helpString),
            tokens(Token::tokenize(commandString)),
            callable(false),
            preContext(_preContext),
            postContext(_postContext)
        {
            if (fn != NO_CALL)
                callable = true;
        }

        void Command::operator()() {
            if (currentContext != preContext && preContext != Context::ALL)
            {
                dialogs.push_back(std::make_shared<DialogOK>("Invalid command within this context."));
                return;
            }

            if(!fn())
            {
                dialogs.push_back(std::make_shared<DialogOK>("Command failed."));
            }
            else
            {
                if (postContext != Context::SAME)
                   currentContext = postContext;
            }
        }


    }
}

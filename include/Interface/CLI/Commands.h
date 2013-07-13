#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <vector>
#include <cstdlib> //TODO remove this

#include "Interface/CLI/CLI.h"
#include "Interface/CLI/Token.h"
#include "Interface/CLI/Context.h"
#include "Interface/CLI/CLIMethods/cliShow.h"
#include "Location/BaseLocation.h"

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
            const std::vector<Token>& getTokens(){return tokens;}
            const Context getContext(){return context;}
            const bool isCallable() {return callable;}
            void operator()();

            std::vector<std::string> args; //hold the arguments for wildcards
        private:
            bool (*fn)();
            std::string commandString;
            std::string helpString;
            std::vector<Token> tokens;
            bool callable;

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
                Command("show", NO_CALL, "Show information about the current view", Context::ALL),
                Command("show adjacent-locations", cliShowLocationRange, "show child locations", Context::LOCATION),
                Command("show items", cliShowItemRange, "show items in this location", Context::LOCATION),
                Command("show individuals", cliShowIndividualRange, "show individuals in this location", Context::LOCATION),

                Command("view", NO_CALL, "Change the current view", Context::ALL),
                Command("view world", cliViewWorld, "view the world", Context::ALL),
                Command("view location", NO_CALL, "view a location", Context::LOCATION),
                Command("view location *", cliViewLocation, "view a location", Context::LOCATION),

                Command("exit", cliExit, "exit the simulation", Context::ALL),
                Command("<CR>", NO_CALL, "Press enter to run the command", Context::NO_CONTEXT)
        };

    }
}
#endif

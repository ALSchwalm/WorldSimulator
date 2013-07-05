#ifndef COMMANDCOMPLETE_H_
#define COMMANDCOMPLETE_H_

#if _WIN32
# include "Utils/curses.h"
#elif __linux__
# include <ncurses.h>
#endif

#include "Interface/Interface.h"
#include "Interface/CLI/Commands.h"
#include "Interface/CLI/Token.h"
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

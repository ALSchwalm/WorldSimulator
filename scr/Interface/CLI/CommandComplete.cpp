#include "Interface/CLI/CommandComplete.h"
#include "Interface/CLI/Commands.h"
#include "Interface/CLI/HelpView.h"
#include "Interface/CLI/Dialog/DialogOK.h"
#include <memory>
#include <sstream>

namespace Interface
{
    namespace CLI
    {

        bool isCompletion(std::vector<Token> input, std::vector<Token> completion)
        {

            if (completion.size() != input.size()) 		//Drop all 'subcommands'
            {
                return false;
            }
            for (unsigned int i=0; i < input.size(); ++i)
            {
                if (input[i] != completion[i])
                    return false;
            }

            return true;
        }

        const std::vector<Command> getPossibleCompletions(std::string input)
        {
            std::vector<Token> tokens = Token::tokenize(input);
            std::vector<Command> completions;
            for (auto command : Commands)
            {
                if (isCompletion(tokens, command.getTokens()) and
                        (command.getContext() == currentContext or
                                command.getContext() == Context::ALL))
                {
                    command.args.clear();
                    for (unsigned int i=0; i < tokens.size(); ++i)
                    {
                        if (command.getTokens()[i].value == "*")	//Hold on to arguments for wildcards
                        {
                            displayView->expandArg(tokens[i]);      //Expand context based arguments
                            command.args.push_back(tokens[i].value);
                        }
                    }
                    completions.push_back(command);
                }
            }
            return completions;
        }

        std::string cliCompleteCommand(std::string input)
        {
            auto completions = getPossibleCompletions(input);
            if (completions.size()==1)
            {
                std::string completion = completions[0].getCommand();
                if (completion[completion.size()-1] != '*')
                    return completion;
            }
            return "";

        }

        void showHelp(std::string input)
        {
            std::vector<Command> completions = getPossibleCompletions(input);

            if (input.back() == ' ')
            {
                auto current_commands = getPossibleCompletions(input.substr(0, input.size()-1));
                if (current_commands.size() >= 1)
                {
                    for (auto command : Commands)
                    {
                        /*
                        * TODO I believe there can only be 1 command in current_commands, but I'm
                        * not certain, so think about this
                        */
                        if (command.getCommand() == "<CR>" and current_commands[0].isCallable())
                        {
                            completions.push_back(command);
                            break;
                        }
                    }
                }
            }

            helpView = std::make_shared<HelpView>(completions);

        }

        void closeHelp()
        {
            //Helpview is a shared_ptr, so no need to clean it up
            helpView = nullptr;
        }


        void callCommand(std::string command)
        {
            if (command.back() == ' ')
            {
                command.pop_back();
            }
            auto commandList = getPossibleCompletions(command);
            if (commandList.size() > 1)
                dialogs.push_back(std::make_shared<DialogOK>("Ambiguous command."));
            else if (commandList.size() < 1)
                dialogs.push_back(std::make_shared<DialogOK>("Unrecognized command."));
            else if (!commandList[0].isCallable())
                dialogs.push_back(std::make_shared<DialogOK>("Invalid command."));
            else
            {
                currentCommand = commandList[0];
                commandList[0]();
                closeHelp();
                displayView->redrawView();
            }
        }


    }

}

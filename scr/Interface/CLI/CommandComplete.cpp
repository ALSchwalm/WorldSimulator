#include "Interface/CLI/CommandComplete.h"
#include "Interface/CLI/Commands.h"
#include "Interface/CLI/HelpView.h"
#include "Interface/CLI/Dialog/DialogOK.h"
#include <memory>

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
				if (isCompletion(tokens, command.getTokens()))
					completions.push_back(command);
			}
			return completions;
		}

		const std::string cliCompleteCommand(std::string input)
		{
			auto completions = getPossibleCompletions(input);
			if (completions.size()==1)
			{
				std::string completion = completions[0].getCommand();
				return completion.substr(input.size(), completion.size()) + " ";
			}
			return "";

		}

		void showHelp(std::string input)
		{
			std::vector<Command> completions = getPossibleCompletions(input);

			helpView = std::make_shared<HelpView>(completions);

		}

		void closeHelp()
		{
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
			else
				commandList[0]();
		}


	}

}

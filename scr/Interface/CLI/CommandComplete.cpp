#include "Interface/CLI/CommandComplete.h"
#include "Interface/CLI/Commands.h"
#include "Interface/CLI/HelpView.h"
#include <memory>

namespace Interface
{
	namespace CLI
	{

		bool isCompletion(std::string input, std::string completion)
		{
			if (input.size() > completion.size())
				return false;
			for (unsigned int i=0; i < input.size(); ++i)
			{
				if (input[i] != completion[i])
					return false;
			}
			return true;
		}

		std::vector<Command> getPossibleCompletions(std::string input)
		{
			std::vector<Command> completions;
			for (auto command : Commands)
			{
				if (isCompletion(input, command.getCommand()))
					completions.push_back(command);
			}
			return completions;
		}

		void showHelp(std::string input)
		{
			std::vector<Command> completions = getPossibleCompletions(input);

			displayView = std::make_shared<HelpView>(completions);

		}


	}

}

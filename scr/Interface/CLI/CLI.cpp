
#include "Interface/CLI/CLI.h"
#include "Interface/CLI/CommandComplete.h"
#include <string>

namespace Interface
{
	namespace CLI
	{
		WINDOW * CLIwin;
		WINDOW * lineWin;

		std::string line;

		void initialize()
		{

			CLIwin = subwin(mainwin, 3, COLS, 0, 0);
			box(CLIwin, 0, 0);
			refresh();
			mvaddstr(1, 2, "Command:");

			lineWin = subwin(CLIwin, 1, COLS-12, 1, 11);

		}

		void handleInput()
		{
			char c = wgetch(lineWin);
			switch(c)
			{
			case '?':
				showHelp(line);
				break;
			case 10:
				wclear(lineWin);
				line="";
				break;
			case 8:
				waddch(lineWin, '\b');
				wdelch(lineWin);
				if (line != "")
					line.erase(line.end()-1);
				break;
			case ERR:
				break;
			default:
				waddch(lineWin, c);
				line += c;
				break;
			}
		}

	}
}





#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"
#include <iostream>
#include <cstdlib>

namespace Interface
{
	WINDOW * mainwin;

	void initialize()
	{
	    if ( (mainwin = initscr()) == NULL ) {
			std::cerr << "Error initializing ncurses" << std::endl;
			exit(EXIT_FAILURE);
	    }

	    keypad(mainwin, true); 	//allow arrow/function keys
	    //nodelay();	//do not wait for input
	    halfdelay(1);
	    noecho();	//do not echo user intput to screen


	    CLI::initialize();

	}
}

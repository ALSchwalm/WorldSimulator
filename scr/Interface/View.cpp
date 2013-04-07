
#include "Interface/View.h"
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
	}
}

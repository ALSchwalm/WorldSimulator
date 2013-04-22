
#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"
#include "Interface/GeneralView.h"
#include "Location/World.h"
#include <iostream>
#include <cstdlib>

namespace Interface
{
	WINDOW * mainwin;
	std::shared_ptr<BaseView> displayView;
	std::shared_ptr<BaseView> helpView;
	CLI::Context currentContext;

	void initialize()
	{
	    if ( (mainwin = initscr()) == NULL ) {
			std::cerr << "Error initializing ncurses" << std::endl;
			exit(EXIT_FAILURE);
	    }

	    keypad(mainwin, true); 	//allow arrow/function keys
	    nodelay(mainwin, true);	//do not wait for input
	    noecho();	//do not echo user intput to screen

	    CLI::initialize();
	    currentContext = CLI::Context::LOCATION;
	    displayView = std::make_shared<GeneralView<Location::Location_ptr> >(Location::World::getInstance());
	}
	void refreshView()
	{
		if (helpView)
			helpView->refreshView();
		else
			displayView->refreshView();
	}

}

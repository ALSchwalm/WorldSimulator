
#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"
#include "Interface/GeneralView.h"
#include "Interface/CLI/HelpView.h"
#include "Location/World.h"
#include "Time/DateManager.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

namespace Interface
{
    WINDOW * mainwin;
    std::shared_ptr<BaseView> displayView;
    std::shared_ptr<HelpView> helpView;
    CLI::Context currentContext;

    void initialize()
    {
        if ( (mainwin = initscr()) == NULL ) {
            throw(std::runtime_error("Error initializing ncurses"));
        }

        keypad(mainwin, true); 	//allow arrow/function keys
        noecho();	//do not echo user intput to screen
        scrollok(mainwin, true);

        CLI::initialize();
        currentContext = CLI::Context::LOCATION;
        displayView = std::make_shared<GeneralView<Location::Location_ptr> >(Location::World::getInstance());
        update_date();
    }


    void update_date()
    {
        mvwprintw(mainwin, LINES-1, 1, Time::now().toString().c_str());
        wrefresh(mainwin);
    }


    void refreshView()
    {
        static Time::Date prev_time = Time::DateManager::getInstance().now();
        if (Time::now() != prev_time)
        {
            prev_time = Time::now();
            update_date();
            if (helpView)
                helpView->refreshView();
            else
                displayView->refreshView();
        }
        wrefresh(CLI::lineWin);
    }

}

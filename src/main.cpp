/*
 * main.cpp
 *
 *  Created on: Mar 1, 2013
 *      Author: Adam
 */

#include <exception>
#include <iostream>
#include <boost/python.hpp>
#include "Utils/Defaults.h"
#include "Utils/Utils.h"
#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"
#include "Time/TimeManager.h"
#include "WorldGen/LocationGen.h"
#include "WorldGen/PopulationGen.h"
#include "WorldGen/ItemGen.h"

int main()
{
    try
    {
        Utils::Logging::initialize();
    	Utils::loadPlugins();

    	WorldGen::LocationGen::seed();
        WorldGen::PopulationGen::seed();
        WorldGen::ItemGen::seed();

        Interface::initialize();

        while(true)
        {
            Time::TimeManager::getInstance().tick();
            Time::TimeManager::getInstance().capRefresh();
            Interface::refreshView();
            Interface::CLI::handleInput();
        }
    }
    catch( boost::python::error_already_set ) {
        PyErr_Print();
    }
    catch (std::exception& e)
    {
        std::cerr << "An unhandled exception occurred: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred." << std::endl;
        return 1;
    }

    return 0;
}

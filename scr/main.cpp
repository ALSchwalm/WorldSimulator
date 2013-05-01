/*
 * main.cpp
 *
 *  Created on: Mar 1, 2013
 *      Author: Adam
 */

#include <exception>
#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"
#include "Time/TimeManager.h"
#include "WorldGen/LocationGen.h"
#include "WorldGen/PopulationGen.h"

int main()
{
	try
	{
		WorldGen::LocationGen::seed();
		WorldGen::PopulationGen::seed();

		Interface::initialize();

		while(true)
		{
			Time::TimeManager::getInstance().tick();
			Time::TimeManager::getInstance().capFPS();
			Interface::refreshView();
			Interface::CLI::handleInput();
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "An unhandled exception occurred: " << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "An unknown exception occured." << std::endl;
		return 1;
	}

	return 0;
}

/*
 * main.cpp
 *
 *  Created on: Mar 1, 2013
 *      Author: Adam
 */

#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"
#include "Time/TimeManager.h"
#include "WorldGen/LocationGen.h"
#include "WorldGen/PopulationGen.h"

int main()
{
	WorldGen::LocationGen::seed();
	WorldGen::PopulationGen::seed();

	Interface::initialize();

	while(true)
	{
		Interface::CLI::handleInput();
		Time::TimeManager::getInstance().tick();
		Time::TimeManager::getInstance().capFPS();
		Interface::refreshView();

	}

	return 0;
}

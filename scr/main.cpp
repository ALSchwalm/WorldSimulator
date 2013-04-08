/*
 * main.cpp
 *
 *  Created on: Mar 1, 2013
 *      Author: Adam
 */

#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"
#include "Event/MoveEvent.h"
#include "Location/World.h"
#include <memory>

int main()
{
	Interface::initialize();
	auto e = std::make_shared<Event::MoveEvent>(nullptr, nullptr);
	Location::World::getInstance()->addEvent(e);

	while(true)
	{
		Interface::CLI::handleInput();
		Interface::refreshView();
	}

	return 0;
}

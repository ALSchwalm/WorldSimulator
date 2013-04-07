/*
 * main.cpp
 *
 *  Created on: Mar 1, 2013
 *      Author: Adam
 */

#include "Interface/View.h"
#include "Interface/Interface.h"
#include "Interface/CLI/CLI.h"
#include "Interface/EventView.h"
#include "Event/MoveEvent.h"
#include "Individual/BaseIndividual.h"
#include "Individual/Person.h"
#include <memory>

int main()
{
	Interface::initialize();
	auto i = std::make_shared<Individual::Person>("test", 0);
	auto e = std::make_shared<Event::MoveEvent>(nullptr, nullptr);
	i->addEvent(e);
	i->addEvent(e);
	i->addEvent(e);
	i->addEvent(e);
	Interface::EventView<std::shared_ptr<Individual::Person> > v(i);

	while(true)
	{
		Interface::CLI::handleInput();
		v.refreshView();
	}

	return 0;
}

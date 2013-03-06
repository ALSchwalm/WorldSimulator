/*
 * main.cpp
 *
 *  Created on: Mar 1, 2013
 *      Author: Adam
 */

#include "Utils/curses.h"
#include "Event/BirthEvent.h"
#include "Event/EventQueue.h"
#include "Individual/Person.h"
#include "Location/Village.h"

#include <iostream>

int main()
{
	auto p = std::make_shared<Individual::Person>("test Person");
	auto l = std::make_shared<Location::Village>("test Location");

	auto e = std::make_shared<Event::BirthEvent>(p, l);

//	Event::EventQueue::getInstance().addEvent(e);
//	Event::EventQueue::getInstance().execute();

	e->run();

	std::cout << l->getIndividuals()[0]->getName() << std::endl;

	return 0;
}

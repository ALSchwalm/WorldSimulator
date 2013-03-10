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
#include "Time/DateManager.h"
#include "Time/TimeManager.h"
#include "Relationship/Relationship.h"

#include <iostream>

int main()
{


	auto l = std::make_shared<Location::Village>("test Location");

	auto p2 = std::make_shared<Individual::Person>("test Person 2", l);
	auto p = std::make_shared<Individual::Person>("test Person", l);

	auto e = std::make_shared<Event::BirthEvent>(Time::now(), p, l);
	auto e2 = std::make_shared<Event::BirthEvent>(Time::now(), p2, l);

	Event::EventQueue::getInstance().addEvent(e2);
	Event::EventQueue::getInstance().addEvent(e);

	Event::EventQueue::getInstance().execute();

	for (auto person : l->getIndividuals() )
		std::cout << person->getName() << " -> " << Relationship::getRelationshipAsString(person->getLocationRelationships(l)[0]->getType())  << std::endl;

	return 0;
}

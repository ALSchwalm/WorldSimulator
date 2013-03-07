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

#include <iostream>

int main()
{
//	auto p2 = std::make_shared<Individual::Person>("test Person 2");
//	auto p = std::make_shared<Individual::Person>("test Person");
//
//	auto l = std::make_shared<Location::Village>("test Location");
//
//	auto e = std::make_shared<Event::BirthEvent>(p, l, Time::now());
//	auto e2 = std::make_shared<Event::BirthEvent>(p2, l, Time::now());
//
//	Event::EventQueue::getInstance().addEvent(e2);
//	Event::EventQueue::getInstance().addEvent(e);
//
//	Event::EventQueue::getInstance().execute();
//
//	for (auto person : l->getIndividuals() )
//		std::cout << person->getName() << std::endl;

	while (true)
	{
		Time::TimeManager::getInstance().capFPS();
		Time::TimeManager::getInstance().tick();
	}

	return 0;
}

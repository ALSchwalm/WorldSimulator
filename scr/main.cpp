/*
 * main.cpp
 *
 *  Created on: Mar 1, 2013
 *      Author: Adam
 */
#include "Action/GoalCreator.h"
#include "Utils/curses.h"
#include "Event/BirthEvent.h"
#include "Event/EventQueue.h"
#include "Individual/Person.h"
#include "Location/Village.h"
#include "Location/World.h"
#include "Time/DateManager.h"
#include "Time/TimeManager.h"
#include "Relationship/Relationship.h"

#include <cassert>
#include <iostream>

int main()
{


	auto l = std::make_shared<Location::Village>(Location::World::getInstance(), "test Location");
	auto l2 = std::make_shared<Location::Village>(l, "test Location2");

	std::cout << "l at "  << l.get() << std::endl;
	for (auto location : l->getLocations())
		std::cout << location->getName() << std::endl;
	std::cout << std::endl;
	std::cout << "l2 at " << l2.get() << std::endl;
	for (auto location : l2->getLocations())
		std::cout << location->getName() << std::endl;
	std::cout << std::endl;

	auto item = std::make_shared<Item::BaseItem>();
	item->setAttribute("edible");


	for (auto item : l2->getItems())
	{
		std::cout << item->getName() << std::endl;
	}


	auto p = std::make_shared<Individual::Person>("test Person", l);
	p->addGoal(Action::GoalCreator::getInstance().createGoal(Action::GoalType::GET_FOOD, p, 0));

	return 0;
}

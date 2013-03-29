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
#include "Condition/Condition.h"
#include "Item/Weapon.h"
#include <cassert>
#include <iostream>
#include <utility>


int main()
{
	auto l = std::make_shared<Location::Village>(Location::World::getInstance(), "test Location");
	auto l2 = std::make_shared<Location::Village>(l, "test Location2");

	auto item = std::make_shared<Item::Weapon>("testWeapon");
	item->setAttribute("edible");

	l2->addItem(item);

	auto p = std::make_shared<Individual::Person>("test Person", l);
	auto p2 = std::make_shared<Individual::Person>("test Person 2", l);

	auto t = Action::GoalCreator::getInstance().createGoal(Action::GoalType::GET_FOOD, p, 0);
	if (t == nullptr)
		std::cout << "Unable to find food." << std::endl;
	else
		p->addGoal(t);

	p->goalTree.execute();
	//std::cout << Event::EventQueue::getInstance();

	Time::Date temp(Time::now()+3);

	while (true)
	{
		std::cout << Event::EventQueue::getInstance().getNextEvent()->getEventName() << std::endl;
		Event::EventQueue::getInstance().execute();
		Time::TimeManager::getInstance().capFPS();
		Time::TimeManager::getInstance().tick();
		std::cout << p->getCurrentLocation()->getName() << std::endl;
		std::cout << Time::DateManager::getInstance().now << std::endl;
//		if (temp == Time::now())
//			break;
	}



	return 0;
}

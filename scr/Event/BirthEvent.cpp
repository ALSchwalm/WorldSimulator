/*
 * BirthEvent.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#include "Event/BirthEvent.h"
#include <iostream> //TODO remove this

namespace Event {

	BirthEvent::BirthEvent(
			std::shared_ptr<Individual::BaseIndividual> i,
			std::shared_ptr<Location::BaseLocation> l) :
			name("Birth"),
			birthPlace(l),
			individual(i)
	{
	}

	BirthEvent::~BirthEvent()
	{
		std::cout << "BirthEvent deleted" << std::endl;
	}

	void BirthEvent::run()
	{
		individual->addEvent(std::shared_ptr<Event::BirthEvent>(this));
		birthPlace->addIndividual(individual);
	}


} /* namespace Event */

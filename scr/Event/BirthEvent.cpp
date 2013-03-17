/*
 * BirthEvent.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#include "Event/BirthEvent.h"
#include "Relationship/Relationship.h"
#include <iostream> //TODO remove this

namespace Event {
	BirthEvent::BirthEvent(
			std::shared_ptr<Individual::BaseIndividual> i,
			std::shared_ptr<Location::BaseLocation> l) :
			BaseEvent("Birth"),
			birthPlace(l),
			individual(i)
	{
	}

	BirthEvent::BirthEvent(
			Time::Date d,
			std::shared_ptr<Individual::BaseIndividual> i,
			std::shared_ptr<Location::BaseLocation> l) :
			BaseEvent(d, "Birth"),
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
		typedef Relationship::Relationship<Individual::BaseIndividual, Location::BaseLocation> rel;

		auto tempRelationship = std::make_shared<rel>(individual, birthPlace, Relationship::RelationshipType::BIRTHPLACE);

		individual->addLocationRelationship(birthPlace, tempRelationship);
		individual->addEvent(std::shared_ptr<BirthEvent>(this));
		birthPlace->addIndividual(individual);
	}


} /* namespace Event */

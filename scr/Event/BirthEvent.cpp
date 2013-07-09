/*
 * BirthEvent.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#include "Event/BirthEvent.h"
#include "Relationship/Relationship.h"

namespace Event {
    BirthEvent::BirthEvent(
            std::shared_ptr<Actor::Individual> i,
            std::shared_ptr<Location::BaseLocation> l) :
            BaseEvent("Birth"),
            birthPlace(l),
            individual(i)
    {
    }

    BirthEvent::BirthEvent(
            Time::Date d,
            std::shared_ptr<Actor::Individual> i,
            std::shared_ptr<Location::BaseLocation> l) :
            BaseEvent(d, "Birth"),
            birthPlace(l),
            individual(i)
    {
    }

    BirthEvent::~BirthEvent()
    {
    }

    void BirthEvent::run()
    {
        individual->addRelationship(birthPlace, Relationship::RelationshipType::BIRTHPLACE);
        individual->addEvent(std::shared_ptr<BirthEvent>(this));
        birthPlace->addIndividual(individual);
    }


} /* namespace Event */

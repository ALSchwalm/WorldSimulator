#include "Event/BirthEvent.h"
#include "Action/Task.h"
#include "Relationship/Relationship.h"
#include "Actor/Individual.h"
#include "Location/BaseLocation.h"

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
        if (sourceTask)
            sourceTask->finished();
    }


} /* namespace Event */

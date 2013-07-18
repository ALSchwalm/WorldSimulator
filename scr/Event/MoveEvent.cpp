#include "Event/MoveEvent.h"

namespace Event {
    MoveEvent::MoveEvent(
            std::shared_ptr<Actor::Individual> i,
            std::shared_ptr<Location::BaseLocation> l) :
            BaseEvent("Move"),
            newLocation(l),
            individual(i)
    {

    }

    MoveEvent::MoveEvent(
            Time::Date d,
            std::shared_ptr<Actor::Individual> i,
            std::shared_ptr<Location::BaseLocation> l) :
            BaseEvent(d, "Move"),
            newLocation(l),
            individual(i)
    {

    }

    MoveEvent::~MoveEvent()
    {
    }

    void MoveEvent::run()
    {
        //if the location is adjacent
        if (individual->getCurrentLocation()->getLocations().find(newLocation) !=
                individual->getCurrentLocation()->getLocations().end()) {
            individual->setCurrentLocation(newLocation);

            if (sourceTask)
                sourceTask->finished();
        }
        else
        {
            if (sourceTask)
                sourceTask->failed();
        }
    }

} /* namespace Event */

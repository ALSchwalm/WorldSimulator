#include "Event/MoveEvent.h"

namespace Event {
	MoveEvent::MoveEvent(
			std::shared_ptr<Individual::BaseIndividual> i,
			std::shared_ptr<Location::BaseLocation> l) :
			BaseEvent("Move"),
			newLocation(l),
			individual(i)
	{
	}

	MoveEvent::MoveEvent(
			Time::Date d,
			std::shared_ptr<Individual::BaseIndividual> i,
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
		individual->setCurrentLocation(newLocation);
	}

} /* namespace Event */

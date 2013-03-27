#include "Event/InterruptEvent.h"

using namespace Event;

InterruptEvent::InterruptEvent(
		Individual::Individual_ptr _source,
		Individual::Individual_ptr _interrupted,
		Action::Goal_ptr _goal) :
		BaseEvent("Interrupt"),
		source(_source),
		interrupted(_interrupted),
		goal(_goal)
{
}

InterruptEvent::InterruptEvent(
		Time::Date d,
		Individual::Individual_ptr _source,
		Individual::Individual_ptr _interrupted,
		Action::Goal_ptr _goal) :
		BaseEvent(d, "Interrupt"),
		source(_source),
		interrupted(_interrupted),
		goal(_goal)
{
}

InterruptEvent::~InterruptEvent()
{
}

void InterruptEvent::run()
{
	interrupted->addGoal(goal);
}

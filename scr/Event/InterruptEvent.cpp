#include "Event/InterruptEvent.h"

using namespace Event;

//InterruptEvent::InterruptEvent(
//		Individual::Individual_ptr _source,
//		Individual::Individual_ptr _interrupted,
//		Action::GoalRequest _goalRequest,
//		unsigned int _priority) :
//		BaseEvent("Interrupt"),
//		source(_source),
//		interrupted(_interrupted),
//		goalRequest(_goalRequest),
//		priority(_priority)
//{
//}
//
//InterruptEvent::InterruptEvent(
//		Time::Date d,
//		Individual::Individual_ptr _source,
//		Individual::Individual_ptr _interrupted,
//		Action::GoalRequest _goalRequest,
//		unsigned int _priority) :
//		BaseEvent(d, "Interrupt"),
//		source(_source),
//		interrupted(_interrupted),
//		goalRequest(_goalRequest),
//		priority(_priority)
//{
//}

InterruptEvent::~InterruptEvent()
{
}

void InterruptEvent::run()
{
//	interrupted->addGoal(goalRequest, priority);
}

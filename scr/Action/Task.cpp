
#include "Action/Task.h"
#include "Event/BaseEvent.h"
#include "Event/EventQueue.h"

using namespace Action;

Task::Task(Event::Event_ptr _event, Goal_ptr _goal) :
		event(_event),
		goal(_goal)
{
}

Task::~Task()
{
}

bool Task::run()
{
	//TODO check for preconditions here

	Event::EventQueue::getInstance().addEvent(event);
	return true;
}

void Task::finished()
{
	goal->taskFinished();
}


#include "Action/Task.h"
#include "Event/BaseEvent.h"
#include "Event/EventQueue.h"
#include "Action/Goal.h"

using namespace Action;

Task::Task(Event::Event_ptr _event, Goal_ptr _goal) :
        event(_event),
        goal(_goal),
        interrupted(false)
{
}

Task::~Task()
{
}

bool Task::run()
{
    //Execute as soon as possible
    event->setSoonestExecution();
    event->setSourceTask(this);

    Event::EventQueue::getInstance().addEvent(event);
    return true;
}

void Task::finished()
{
    if (!interrupted)
        goal->taskFinished();
}

void Task::interrupt()
{
    interrupted = true;
    event->interrupt();
}

void Task::failed()
{

}

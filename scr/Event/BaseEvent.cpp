
#include "Event/BaseEvent.h"
#include "Event/EventQueue.h"
#include <iostream>

using namespace Event;

void BaseEvent::interrupt()
{
    Event::EventQueue::getInstance().removeEvent(std::shared_ptr<BaseEvent>(this));
}

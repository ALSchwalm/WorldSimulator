
#include "Event/BaseEvent.h"

#include <iostream>

using namespace Event;

void BaseEvent::run()
{
	std::cerr << "Error: Attempt to run BaseEvent" << std::endl;
}

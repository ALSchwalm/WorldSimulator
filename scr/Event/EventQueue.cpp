/*
 * EventQueue.cpp
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#include "Event/EventQueue.h"

namespace Event {


EventQueue & EventQueue::getInstance()
{
	EventQueue e;
	return e;
}


EventQueue::EventQueue()
{

}



void EventQueue::execute()
{
	for (unsigned int i = 0; i<queue.size(); i++)
	{
		queue.front()->run();
		queue.pop();
	}
}

} /* namespace Event */

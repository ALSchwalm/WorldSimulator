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
    static EventQueue e;
    return e;
}


EventQueue::EventQueue()
{

}



void EventQueue::execute()
{
    for( auto i = queue.begin(); i != queue.end(); )
    {
        if ( (*i)->getExecutionDate() == Time::now() )
        {
            (*i)->run();
            i = queue.erase(i);
        }
        else
        {
            ++i;
        }

    }
}

} /* namespace Event */

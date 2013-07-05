/*
 * EndTaskEvent.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#include "Event/EndTaskEvent.h"
#include "Action/Task.h"

namespace Event {

    EndTaskEvent::EndTaskEvent(
            Time::Date d,
            Action::Task_ptr _callBackTask) :
            BaseEvent(d, "EndTask"),
            callBackTask(_callBackTask)
    {
    }

    EndTaskEvent::~EndTaskEvent()
    {
    }

    void EndTaskEvent::run()
    {
        callBackTask->finished();
    }


} /* namespace Event */

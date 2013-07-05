/*
 * EventQueue.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_

#include <list>
#include <memory>
#include <algorithm>
#include "Event/BaseEvent.h"
#include "Time/DateManager.h"

namespace Event {

    class EventQueue {
    public:
        static EventQueue & getInstance();

        void execute();

        Event_ptr getNextEvent()
        {
            return queue.front();
        }

        void addEvent(Event::Event_ptr e) {queue.push_back(e);}

        void removeEvent(Event::Event_ptr e) { queue.erase(std::remove(queue.begin(), queue.end(), e)); }

    private:
        EventQueue();

        std::list<std::shared_ptr<BaseEvent>> queue;

    };

} /* namespace Event */
#endif /* EVENTQUEUE_H_ */

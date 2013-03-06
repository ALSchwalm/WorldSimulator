/*
 * EventQueue.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_

#include <queue>
#include <memory>
#include "Event/BaseEvent.h"

namespace Event {

	class EventQueue {
	public:
		static EventQueue & getInstance();

		void execute();

		std::shared_ptr<BaseEvent> getNextEvent()
		{
			std::shared_ptr<BaseEvent> t = queue.front();
			queue.pop();
			return t;
		}

		void addEvent(std::shared_ptr<BaseEvent> e) {queue.push(e);}

	private:
		EventQueue();

		std::queue<std::shared_ptr<BaseEvent>> queue;

	};

} /* namespace Event */
#endif /* EVENTQUEUE_H_ */

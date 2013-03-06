/*
 * EventQueue.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_

#include <vector>
#include <memory>
#include "Event/BaseEvent.h"
#include "Time/DateManager.h"

namespace Event {

	class EventQueue {
	public:
		static EventQueue & getInstance();

		void execute();

		std::shared_ptr<BaseEvent> getNextEvent()
		{
			return queue.front();
		}

		void addEvent(std::shared_ptr<BaseEvent> e) {queue.push_back(e);}

	private:
		EventQueue();

		std::vector<std::shared_ptr<BaseEvent>> queue;

	};

} /* namespace Event */
#endif /* EVENTQUEUE_H_ */

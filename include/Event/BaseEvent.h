/*
 * Event.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include <Event/Event.h>
#include <Time/Date.h>
#include <memory>

namespace Event
{
	typedef std::shared_ptr<BaseEvent> Event_ptr;

	class BaseEvent {
	public:
		virtual ~BaseEvent(){};

		virtual std::string getEventName() = 0;
		virtual EventType getEventType() = 0;
		virtual Time::Date getExecutionDate() = 0;

		virtual void run() = 0;

	};

}
#endif /* EVENT_H_ */

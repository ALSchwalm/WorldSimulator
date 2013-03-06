/*
 * Event.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include <Event/Event.h>
#include <string>

namespace Event
{
	class BaseEvent {
	public:
		virtual ~BaseEvent(){};

		virtual std::string getEventName() = 0;
		virtual EventType getEventType() = 0;

		virtual void run() = 0;

	};

}
#endif /* EVENT_H_ */

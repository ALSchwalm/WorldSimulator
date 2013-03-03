/*
 * Event.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <string>
#include <vector>

namespace Event
{
	enum EventType
	{
		BIRTH_EVENT,

		//Insert events befor this
		NUM_OF_EVENTS
	};


	class BaseEvent {
	public:
		virtual ~BaseEvent(){};

		virtual std::string getEventName() = 0;
		virtual EventType getEventType() = 0;

	};

	typedef std::vector<BaseEvent*> EventHistory;
}
#endif /* EVENT_H_ */

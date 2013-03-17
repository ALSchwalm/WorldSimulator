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

	class BaseEvent
	{
	public:
		virtual ~BaseEvent(){};

		virtual std::string getEventName() {return name;}
		virtual EventType getEventType() {return EVENT_ERROR;}

		virtual Time::Date getExecutionDate(){return executionDate;}
		virtual void setExecutionDate(Time::Date newDate) {executionDate = newDate;}

		virtual void run();

	protected:
		BaseEvent(std::string s) : executionDate(Time::Date(0, Time::Month::January, Time::Day::Monday)), name(s){}
		BaseEvent(Time::Date t, std::string s) : executionDate(t), name(s){}

	private:
		Time::Date executionDate;
		std::string name;


	};

}
#endif /* EVENT_H_ */

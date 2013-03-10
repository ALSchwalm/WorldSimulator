/*
 * BirthEvent.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef ENDTASKEVENT_H_
#define ENDTASKEVENT_H_

#include <Event/Event.h>
#include <Event/BaseEvent.h>
#include <Action/Task.h>
#include <Time/Date.h>

namespace Event
{

	class EndTaskEvent : public BaseEvent
	{
	public:
		EndTaskEvent(
			Time::Date executionDate,
			Action::Task_ptr callBackTask
		);
		~EndTaskEvent();

		EventType getEventType() { return EventType::END_TASK_EVENT;};
		std::string getEventName() {return name;};

		Time::Date getExecutionDate() {return executionDate;}

		void run();


	private:
		std::string name;
		Action::Task_ptr callBackTask;
		Time::Date executionDate;

	};

}
#endif /* BIRTHEVENT_H_ */

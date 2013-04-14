#ifndef INTERRUPTEVENT_H_
#define INTERRUPTEVENT_H_

#include <Event/Event.h>
#include <Event/BaseEvent.h>
#include <Individual/Person.h>
#include <Action/Goal.h>

namespace Event
{

	class InterruptEvent : public BaseEvent
	{
	public:
//		InterruptEvent(
//				Individual::Individual_ptr,
//				Individual::Individual_ptr,
//				Action::GoalRequest,
//				unsigned int
//		);
//
//		InterruptEvent(
//				Time::Date,
//				Individual::Individual_ptr,
//				Individual::Individual_ptr,
// 				unsigned int
//		);
		InterruptEvent();
		~InterruptEvent();

		EventType getEventType() { return EventType::INTERRUPT;};

		void run();


	private:
		Individual::Individual_ptr source;
		Individual::Individual_ptr interrupted;

		unsigned int priority;
	};

}
#endif

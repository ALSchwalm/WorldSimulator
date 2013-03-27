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
		InterruptEvent(
				Individual::Individual_ptr,
				Individual::Individual_ptr,
				Action::Goal_ptr
		);

		InterruptEvent(
				Time::Date,
				Individual::Individual_ptr,
				Individual::Individual_ptr,
				Action::Goal_ptr
		);
		~InterruptEvent();

		EventType getEventType() { return EventType::INTERRUPT_EVENT;};

		void run();


	private:
		Individual::Individual_ptr source;
		Individual::Individual_ptr interrupted;

		Action::Goal_ptr goal;

	};

}
#endif

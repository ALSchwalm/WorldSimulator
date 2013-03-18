#ifndef MOVEEVENT_H_
#define MOVEEVENT_H_

#include <Event/Event.h>
#include <Event/BaseEvent.h>
#include <Individual/Person.h>
#include <Location/BaseLocation.h>

namespace Event
{

	class MoveEvent : public BaseEvent
	{
	public:
		MoveEvent(
				std::shared_ptr<Individual::BaseIndividual>,
				std::shared_ptr<Location::BaseLocation>
		);

		MoveEvent(
				Time::Date,
				std::shared_ptr<Individual::BaseIndividual>,
				std::shared_ptr<Location::BaseLocation>
		);
		~MoveEvent();

		EventType getEventType() { return EventType::MOVE_EVENT;};

		void run();


	private:
		std::shared_ptr<Location::BaseLocation> newLocation;
		std::shared_ptr<Individual::BaseIndividual> individual;

	};

}
#endif

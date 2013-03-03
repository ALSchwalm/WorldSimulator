/*
 * BirthEvent.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef BIRTHEVENT_H_
#define BIRTHEVENT_H_

#include <Event/BaseEvent.h>
#include <Individual/Person.h>

namespace Event
{

	class BirthEvent : public BaseEvent
	{
	public:
		BirthEvent();

		EventType getEventType() { return EventType::BIRTH_EVENT;};
		std::string getEventName() {return name;};

		Individual::Person * run();


	private:
		std::string name;

	};

}
#endif /* BIRTHEVENT_H_ */

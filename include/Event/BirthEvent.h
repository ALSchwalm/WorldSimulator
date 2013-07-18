/*
 * BirthEvent.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef BIRTHEVENT_H_
#define BIRTHEVENT_H_

#include <Event/Event.h>
#include <Event/BaseEvent.h>
#include <Location/BaseLocation.h>

namespace Event
{

    class BirthEvent : public BaseEvent
    {
    public:
        BirthEvent(
                std::shared_ptr<Actor::Individual>,
                std::shared_ptr<Location::BaseLocation>
        );

        BirthEvent(
                Time::Date,
                std::shared_ptr<Actor::Individual>,
                std::shared_ptr<Location::BaseLocation>
        );
        ~BirthEvent();

        EventType getEventType() const { return EventType::BIRTH;};
        void run();


    private:
        std::shared_ptr<Location::BaseLocation> birthPlace;
        std::shared_ptr<Actor::Individual> individual;

    };

}
#endif /* BIRTHEVENT_H_ */

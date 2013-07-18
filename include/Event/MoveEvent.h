#ifndef MOVEEVENT_H_
#define MOVEEVENT_H_

#include <Event/Event.h>
#include <Event/BaseEvent.h>
#include <Location/BaseLocation.h>

namespace Event
{

    class MoveEvent : public BaseEvent
    {
    public:
        MoveEvent(
                std::shared_ptr<Actor::Individual>,
                std::shared_ptr<Location::BaseLocation>
        );

        MoveEvent(
                Time::Date,
                std::shared_ptr<Actor::Individual>,
                std::shared_ptr<Location::BaseLocation>
        );
        ~MoveEvent();

        EventType getEventType() const { return EventType::MOVE;};

        void run();


    private:
        std::shared_ptr<Location::BaseLocation> newLocation;
        std::shared_ptr<Actor::Individual> individual;

    };

}
#endif

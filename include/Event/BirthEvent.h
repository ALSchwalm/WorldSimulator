#ifndef BIRTHEVENT_H_
#define BIRTHEVENT_H_

#include <Event/Event.h>
#include <Event/BaseEvent.h>

namespace Location
{
    class BaseLocation;
    using Location_ptr = std::shared_ptr<BaseLocation>;
}

namespace Actor
{
    class Individual;
    using Individual_ptr = std::shared_ptr<Individual>;
}

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

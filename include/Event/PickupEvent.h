#ifndef PICKUPEVENT_H_
#define PICKUPEVENT_H_

#include "Event/Event.h"
#include "Event/BaseEvent.h"

namespace Item
{
    class BaseItem;
    using Item_ptr = std::shared_ptr<BaseItem>;
}

namespace Actor
{
    class Individual;
    using Individual_ptr = std::shared_ptr<Individual>;
}

namespace Event
{
    class PickupEvent : public BaseEvent
    {
    public:
        PickupEvent(Item::Item_ptr,
                    Actor::Individual_ptr);

        ~PickupEvent();

        EventType getEventType() const { return EventType::PICKUP;}

        void run();


    private:
        Item::Item_ptr item;
        Actor::Individual_ptr individual;

    };

}
#endif

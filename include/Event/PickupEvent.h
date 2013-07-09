#ifndef PICKUPEVENT_H_
#define PICKUPEVENT_H_

#include "Event/Event.h"
#include "Item/BaseItem.h"
#include "Location/BaseLocation.h"

namespace Event
{
    class PickupEvent : public BaseEvent
    {
    public:
        PickupEvent(
                Item::Item_ptr,
                Actor::Individual_ptr);

        ~PickupEvent();

        EventType getEventType() { return EventType::PICKUP;}

        void run();


    private:
        Item::Item_ptr item;
        Actor::Individual_ptr individual;

    };

}
#endif

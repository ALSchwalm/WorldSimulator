#include "Event/PickupEvent.h"
#include "Item/ItemManager.h"
#include "Action/Task.h"

namespace Event {
    PickupEvent::PickupEvent(Item::Item_ptr _item, Actor::Individual_ptr _individual) :
            BaseEvent("Pickup"),
            item(_item),
            individual(_individual)
    {
    }

    PickupEvent::~PickupEvent()
    {
    }

    void PickupEvent::run()
    {
        if (Item::ItemManager::getInstance().moveItem(item, individual->getCurrentLocation(), individual))
        {
            if (sourceTask)
                sourceTask->finished();
        }
        else
        {
            if (sourceTask)
                sourceTask->failed();
        }
    }

} /* namespace Event */

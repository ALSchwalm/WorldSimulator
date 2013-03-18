#include "Event/PickupEvent.h"
#include "Item/ItemManager.h"

namespace Event {
	PickupEvent::PickupEvent(Item::Item_ptr _item, Individual::Individual_ptr _individual) :
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
		Item::ItemManager::getInstance().moveItem(item, individual->getCurrentLocation(), individual);
	}

} /* namespace Event */

#include "Item/ItemManager.h"

using namespace Item;

ItemManager & ItemManager::getInstance()
{
	static ItemManager m;
	return m;
}

ItemManager::ItemManager()
{

}

template <typename T, typename U>
bool ItemManager::moveItem(Item_ptr item, T source, U destination)
{
	if (source->removeItem(item))
	{
		destination->addItem(item);
		return true;
	}
	return false;
}

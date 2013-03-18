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

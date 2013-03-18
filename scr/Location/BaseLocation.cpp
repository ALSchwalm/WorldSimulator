#include "Location/BaseLocation.h"
#include <algorithm>

using namespace Location;

void BaseLocation::addLocation(Location::Location_ptr l)
{
	if (l.get() != this)
		locations.insert(l);
	if (l != nullptr)
		l->addOnewayLocation(std::shared_ptr<BaseLocation>(this));
}
void BaseLocation::operator+=(Location::Location_ptr rhs)
{
	addLocation(rhs);
}

void BaseLocation::addOnewayLocation (Location::Location_ptr l)
{
	if (l.get() != this)
		locations.insert(l);
}

bool BaseLocation::removeItem(Item::Item_ptr i)
{
	if (std::find(items.begin(), items.end(), i) == items.end())
	{
		return false;
	}
	else
	{
		items.erase(std::find(items.begin(), items.end(), i));
		return true;
	}

}

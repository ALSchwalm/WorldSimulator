#include "Location/BaseLocation.h"
#include <algorithm>

using namespace Location;

void BaseLocation::addLocation(Location::Location_ptr l)
{
	if (l == nullptr)
		return;
	else if (l.get() != this)
		locations.insert(l);
}
void BaseLocation::operator+=(Location::Location_ptr rhs)
{
	addLocation(rhs);
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

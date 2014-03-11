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

bool BaseLocation::hasAttribute(const std::string& s) {
	auto location = attributes.find(s);
	if (location != attributes.end())
	{
		return location->second;
	}
	return false;
}

const std::unordered_set<Location_ptr> BaseLocation::getLocationsByAttribute(std::string s)
{
    std::unordered_set<Location_ptr> temp;
    for (auto location : locations)
    {
        if (location->hasAttribute(s))
        {
            temp.insert(location);
        }
    }
    return temp;
}

const std::unordered_set<Location_ptr> BaseLocation::getLocationsByType(LocationType l)
{
    std::unordered_set<Location_ptr> temp;
    for (auto location : locations)
    {
        if (location->getLocationType() == l)
        {
            temp.insert(location);
        }
    }
    return temp;
}

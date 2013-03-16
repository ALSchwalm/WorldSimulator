#include "Location/BaseLocation.h"

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


#include "WorldGen/LocationGen.h"
#include "Location/World.h"
#include "Location/Region.h"

#include <cstdlib>
#include <memory>

using namespace WorldGen;

LocationGen & LocationGen::getInstance()
{
	static LocationGen locationGen;
	return locationGen;
}

void LocationGen::seed()
{
	unsigned int numberRegions = (rand() % 5 + 1);
	for (unsigned int i = 0; i < numberRegions; ++i)
	{
		Location::World::getInstance()->addLocation(
				std::make_shared<Location::Region>("TempRegion")
				);
	}
}

LocationGen::LocationGen()
{

}


#include "WorldGen/LocationGen.h"
#include "Location/World.h"
#include "Location/Region.h"
#include "Location/Location.h"
#include "Utils/Markov.h"

#include <cstdlib>
#include <memory>
#include <iostream> //TODO remove this

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
		auto region = std::make_shared<Location::Region>( Utils::Markov::getInstance().getProperWord());
		Location::addLocations(Location::World::getInstance(), region);
	}
}

LocationGen::LocationGen()
{

}

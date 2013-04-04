
#include "WorldGen/LocationGen.h"
#include "Location/World.h"
#include "Location/Region.h"
#include "Location/Village.h"
#include "Location/Location.h"
#include "Utils/Markov.h"

#include <cstdlib>
#include <memory>

using namespace WorldGen;

namespace WorldGen
{
	namespace LocationGen
	{

void seed()
{
	unsigned int numberRegions = (rand() % 5) + 1;
	for (unsigned int i = 0; i < numberRegions; ++i)
	{
		auto region = std::make_shared<Location::Region>( Utils::Markov::getInstance().getProperWord());
		Location::addLocations(Location::World::getInstance(), region);
	}

	for (auto region : Location::World::getInstance()->getLocations())
	{
		unsigned int numberCities = (rand() % 10) + 1;
		for (unsigned int i=0; i < numberCities; ++i) //TODO assign nationality here
		{
			auto city = std::make_shared<Location::Village>(Utils::Markov::getInstance().getProperWord());
			Location::addLocations(region, city);
		}
	}
}

	}
}

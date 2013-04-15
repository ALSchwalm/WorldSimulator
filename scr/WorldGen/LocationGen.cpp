
#include "WorldGen/LocationGen.h"
#include "Location/World.h"
#include "Location/Region.h"
#include "Location/Village.h"
#include "Location/Location.h"
#include "Utils/Markov.h"
#include "Utils/Config.h"

#include <cstdlib>
#include <memory>

using namespace WorldGen;

namespace WorldGen
{
	namespace LocationGen
	{

const unsigned int MAX_REGIONS = Utils::Config::getInstance().getValue("LocationGen", "MAX_REGIONS");
const unsigned int MIN_REGIONS = Utils::Config::getInstance().getValue("LocationGen", "MIN_REGIONS");

const unsigned int MAX_CITIES_PER_REGION = Utils::Config::getInstance().getValue("LocationGen", "MAX_CITIES_PER_REGION");
const unsigned int MIN_CITIES_PER_REGION = Utils::Config::getInstance().getValue("LocationGen", "MIN_CITIES_PER_REGION");

void seed()
{
	unsigned int numberRegions = (rand() % (MAX_REGIONS-MIN_REGIONS)) + MIN_REGIONS;
	for (unsigned int i = 0; i < numberRegions; ++i)
	{
		auto region = std::make_shared<Location::Region>( Utils::Markov::getInstance().getProperWord());
		Location::addLocations(Location::World::getInstance(), region);
	}

	for (auto region : Location::World::getInstance()->getLocations())
	{
		unsigned int numberCities = (rand() % (MAX_CITIES_PER_REGION-MIN_CITIES_PER_REGION)) + MIN_CITIES_PER_REGION;
		for (unsigned int i=0; i < numberCities; ++i) //TODO assign nationality here
		{
			auto city = std::make_shared<Location::Village>(Utils::Markov::getInstance().getProperWord());
			Location::addLocations(region, city);
		}
	}
}

	}
}

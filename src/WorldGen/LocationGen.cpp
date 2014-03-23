
#include "WorldGen/LocationGen.h"
#include "Location/World.h"
#include "Location/Region.h"
#include "Location/Village.h"
#include "Location/Location.h"
#include "Utils/Markov.h"
#include "Utils/Config.h"
#include "Utils/Utils.h"
#include <boost/log/trivial.hpp>
#include <memory>

using namespace WorldGen;

namespace WorldGen
{
    namespace LocationGen
    {

        const unsigned int MAX_REGIONS = Utils::Config::getInstance().getValue("LocationGen.MAX_REGIONS");
        const unsigned int MIN_REGIONS = Utils::Config::getInstance().getValue("LocationGen.MIN_REGIONS");

        const unsigned int MAX_CITIES_PER_REGION = Utils::Config::getInstance().getValue("LocationGen.MAX_CITIES_PER_REGION");
        const unsigned int MIN_CITIES_PER_REGION = Utils::Config::getInstance().getValue("LocationGen.MIN_CITIES_PER_REGION");

void seed()
{
    auto numberRegions = Utils::uniform(MIN_REGIONS, MAX_REGIONS);
    BOOST_LOG_TRIVIAL(info) << "Adding " << numberRegions << " regions to world.";
    for (int i = 0; i < numberRegions; ++i)
    {
        auto region = std::make_shared<Location::Region>( Utils::Markov::getInstance().getRegionName());
        Location::connectLocations(Location::World::getInstance(), region);
    }

    for (auto region : Location::World::getInstance()->getLocations())
    {
        auto numberCities = Utils::uniform(MIN_CITIES_PER_REGION, MAX_CITIES_PER_REGION);
        BOOST_LOG_TRIVIAL(info) << "Adding " << numberCities << " locations to region: " << region->getName();
        for (int i=0; i < numberCities; ++i) //TODO assign nationality here
        {
            auto city = std::make_shared<Location::Village>(Utils::Markov::getInstance().getVillageName());
            Location::connectLocations(region, city);
        }
    }
}

    }
}

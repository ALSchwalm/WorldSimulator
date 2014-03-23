#include "WorldGen/LocationGen.h"
#include "WorldGen/PopulationGen.h"
#include "WorldGen/ItemGen.h"
#include "Location/World.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(WorldGen)

BOOST_AUTO_TEST_CASE(SeedLocations)
{
    WorldGen::LocationGen::seed();

    BOOST_CHECK_GE(Location::World::getInstance()->getLocations().size(), WorldGen::LocationGen::MIN_REGIONS);
    BOOST_CHECK_LE(Location::World::getInstance()->getLocations().size(), WorldGen::LocationGen::MAX_REGIONS);

    for (const auto& region : Location::World::getInstance()->getLocations())
    {
        BOOST_CHECK_GE(region->getLocations().size(), WorldGen::LocationGen::MIN_CITIES_PER_REGION);
        BOOST_CHECK_LE(region->getLocations().size(), WorldGen::LocationGen::MAX_CITIES_PER_REGION);
    }
}

BOOST_AUTO_TEST_CASE(SeedPopulation)
{
    WorldGen::PopulationGen::seed();

    for (const auto& region : Location::World::getInstance()->getLocations())
    {
        for (const auto& city : region->getLocationsByAttribute("habitable"))
        {
            unsigned int total = 0;
            for (const auto& house : city->getLocationsByType(Location::CONTAINER)) {
                BOOST_CHECK_GE(house->getIndividuals().size(), 1);
                BOOST_CHECK_LE(house->getIndividuals().size(), 5);
                total += house->getIndividuals().size();
            }
            BOOST_CHECK_GE(total, WorldGen::PopulationGen::INITIAL_MIN_POPULATION);
            BOOST_CHECK_LE(total, WorldGen::PopulationGen::INITIAL_MAX_POPULATION);
        }

    }
}


BOOST_AUTO_TEST_CASE(SeedItems)
{
    WorldGen::ItemGen::seed();

    for (const auto& region : Location::World::getInstance()->getLocations())
    {
        for (const auto& city : region->getLocationsByAttribute("habitable"))
        {
            for (const auto& house : city->getLocationsByType(Location::CONTAINER))
            {
                if (!house->getIndividuals().empty()){}
                //EXPECT_FALSE(house->getItems().empty());
            }
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()

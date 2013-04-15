#include "WorldGen/LocationGen.h"
#include "WorldGen/PopulationGen.h"
#include "Location/World.h"
#include "gtest/gtest.h"

TEST(WorldGenTest, SeedLocations)
{
	WorldGen::LocationGen::seed();

	EXPECT_GE(Location::World::getInstance()->getLocations().size(), WorldGen::LocationGen::MIN_REGIONS);
	EXPECT_LE(Location::World::getInstance()->getLocations().size(), WorldGen::LocationGen::MAX_REGIONS);

	for (auto region : Location::World::getInstance()->getLocations())
	{
		EXPECT_GE(region->getLocations().size(), WorldGen::LocationGen::MIN_CITIES_PER_REGION);
		EXPECT_LE(region->getLocations().size(), WorldGen::LocationGen::MAX_CITIES_PER_REGION);
	}
}

TEST(WorldGenTest, SeedPopulation)
{
	WorldGen::PopulationGen::seed();

	for (auto region : Location::World::getInstance()->getLocations())
	{
		for (auto city : region->getLocationsByAttribute("habitable"))
		{
				EXPECT_TRUE(city->getIndividuals().size() >= 100);
				EXPECT_TRUE(city->getIndividuals().size() <= 300);
		}

	}
}

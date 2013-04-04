#include "WorldGen/LocationGen.h"
#include "WorldGen/PopulationGen.h"
#include "Location/World.h"
#include "gtest/gtest.h"

#include <vector>
#include <iostream> //TODO remove this

TEST(WorldGenTest, SeedLocations)
{
	WorldGen::LocationGen::seed();

	EXPECT_TRUE(Location::World::getInstance()->getLocations().size() > 0);
	EXPECT_TRUE(Location::World::getInstance()->getLocations().size() < 6);

	for (auto region : Location::World::getInstance()->getLocations())
	{
		EXPECT_TRUE(region->getLocations().size() > 0);
		EXPECT_TRUE(region->getLocations().size() <= 11);
	}
}

TEST(WorldGenTest, SeedPopulation)
{

	for (auto region : Location::World::getInstance()->getLocations())
	{
		for (auto city : region->getLocations())
		{
			if (city->hasAttribute("habitable"))
			{
				EXPECT_TRUE(city->getIndividuals().size() > 0);
				EXPECT_TRUE(city->getIndividuals().size() < 300);
			}
		}

	}
}

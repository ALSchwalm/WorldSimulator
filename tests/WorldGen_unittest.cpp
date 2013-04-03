#include "WorldGen/LocationGen.h"
#include "Location/World.h"
#include "gtest/gtest.h"

#include <vector>

TEST(WorldGenTest, SeedLocations)
{
	WorldGen::LocationGen::seed();

	EXPECT_TRUE(Location::World::getInstance()->getLocations().size() > 0 && Location::World::getInstance()->getLocations().size() < 6);
}

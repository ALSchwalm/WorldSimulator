#include "gtest/gtest.h"

#include <algorithm>

#include "Location/BaseLocation.h"
#include "Location/Village.h"
#include "Location/World.h"
#include "Location/Location.h"
#include "Item/ItemFactory.h"

TEST(LocationTest, HasAttribute)
{

	auto location = std::make_shared<Location::Village>("TestVillage");

	location->setAttribute("test");

	EXPECT_TRUE(location->hasAttribute("test"));
	EXPECT_FALSE(location->hasAttribute("other"));
}

TEST(LocationTest, AddItems)
{

	auto location = std::make_shared<Location::Village>("TestVillage");
	auto item = Item::itemFactories[0]->make();
	auto item2 = Item::itemFactories[0]->make();

	location->addItem(item);

	EXPECT_TRUE(std::count(location->getItems().begin(), location->getItems().end(), item) == 1 );
	EXPECT_FALSE(std::count(location->getItems().begin(), location->getItems().end(), item2) != 0);
}

TEST(LocationTest, RemoveItems)
{

	auto location = std::make_shared<Location::Village>("TestVillage");
	auto item = Item::itemFactories[0]->make();
	auto item2 = Item::itemFactories[0]->make();

	location->addItem(item);

	EXPECT_TRUE(location->removeItem(item));
	EXPECT_FALSE(location->removeItem(item));
	EXPECT_FALSE(location->removeItem(item2));
}

TEST(LocationTest, AddLocationStandard)
{

	auto location = std::make_shared<Location::Village>("TestVillage");
	auto location2 = std::make_shared<Location::Village>("TestVillage2");

	Location::addLocations(location, location2);

	EXPECT_TRUE(std::count(location->getLocations().begin(), location->getLocations().end(), location2) == 1);
	EXPECT_TRUE(std::count(location2->getLocations().begin(), location->getLocations().end(), location) == 1);
	EXPECT_FALSE(std::count(location->getLocations().begin(), location->getLocations().end(), location) != 0);
	EXPECT_FALSE(std::count(location2->getLocations().begin(), location->getLocations().end(), location2) != 0);
}

TEST(LocationTest, AddLocationWorld)
{

	auto location = std::make_shared<Location::Village>("TestVillage");

	Location::addLocations(Location::World::getInstance(), location);

	EXPECT_TRUE(std::count(location->getLocations().begin(), location->getLocations().end(), Location::World::getInstance()) == 1);
	EXPECT_TRUE(std::count(Location::World::getInstance()->getLocations().begin(), Location::World::getInstance()->getLocations().end(), location) == 1);
	EXPECT_FALSE(std::count(location->getLocations().begin(), location->getLocations().end(), location) != 0);
	EXPECT_FALSE(std::count(Location::World::getInstance()->getLocations().begin(), Location::World::getInstance()->getLocations().end(), Location::World::getInstance()) != 0);
}

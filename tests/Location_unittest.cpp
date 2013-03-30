#include "gtest/gtest.h"

#include <algorithm>
#include "Location/BaseLocation.h"
#include "Location/Village.h"
#include "Item/Weapon.h"

TEST(LocationTest, HasAttribute)
{

	auto location = std::make_shared<Location::Village>(nullptr, "TestVillage");

	location->setAttribute("test");

	EXPECT_TRUE(location->hasAttribute("test"));
	EXPECT_FALSE(location->hasAttribute("other"));
}

TEST(LocationTest, AddItems)
{

	auto location = std::make_shared<Location::Village>(nullptr, "TestVillage");
	auto item = std::make_shared<Item::Weapon>("TestWeapon");
	auto item2 = std::make_shared<Item::Weapon>("TestWeapon2");

	location->addItem(item);

	EXPECT_TRUE(std::count(location->getItems().begin(), location->getItems().end(), item) == 1 );
	EXPECT_FALSE(std::count(location->getItems().begin(), location->getItems().end(), item2) != 0);
}

TEST(LocationTest, RemoveItems)
{

	auto location = std::make_shared<Location::Village>(nullptr, "TestVillage");
	auto item = std::make_shared<Item::Weapon>("TestWeapon");
	auto item2 = std::make_shared<Item::Weapon>("TestWeapon2");

	location->addItem(item);

	EXPECT_TRUE(location->removeItem(item));
	EXPECT_FALSE(location->removeItem(item));
	EXPECT_FALSE(location->removeItem(item2));
}

TEST(LocationTest, AddLocation)
{

	auto location = std::make_shared<Location::Village>(nullptr, "TestVillage");
	auto location2 = std::make_shared<Location::Village>(location, "TestVillage2");

	EXPECT_TRUE(std::count(location->getLocations().begin(), location->getLocations().end(), location2) == 1);
	EXPECT_TRUE(std::count(location2->getLocations().begin(), location->getLocations().end(), location) == 1);
	EXPECT_FALSE(std::count(location->getLocations().begin(), location->getLocations().end(), location) != 0);
	EXPECT_FALSE(std::count(location2->getLocations().begin(), location->getLocations().end(), location2) != 0);
}


#include "Item/BaseItem.h"
#include "Item/Weapon.h"
#include "Item/Container.h"
#include "Location/BaseLocation.h"
#include "Location/Village.h"
#include "Location/World.h"
#include "Location/Location.h"
#include "gtest/gtest.h"


TEST(ItemTest, HasAttribute)
{

	auto item = std::make_shared<Item::Weapon<Item::SWORD>>("TestWeapon");

	item->setAttribute("old");

	EXPECT_TRUE(item->hasAttribute("old"));
	EXPECT_FALSE(item->hasAttribute("other"));
}


TEST(ItemTest, Container)
{
	auto container = std::make_shared<Item::Container<Item::BARREL>>();
	auto item = std::make_shared<Item::Weapon<Item::SWORD>>("Test weapon");

	container->addItem(item);
	Location::addLocations(Location::World::getInstance(), container);

	EXPECT_EQ(container->getLocations().size(), 1u);
	EXPECT_EQ(container->getItems().size(),  1u);
}

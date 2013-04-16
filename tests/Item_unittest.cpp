
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

	auto item = std::make_shared<Item::Weapon>("TestWeapon");


	item->setAttribute("old");

	EXPECT_TRUE(item->hasAttribute("old"));
	EXPECT_FALSE(item->hasAttribute("other"));
}


TEST(ItemTest, Container)
{
	auto container = std::make_shared<Item::Container>(Item::ContainerType::BARREL);
	auto item = std::make_shared<Item::Weapon>("Test weapon");

	container->addItem(item);
	Location::addLocations(Location::World::getInstance(), container);

	EXPECT_EQ(container->getLocations().size(), (unsigned int) 1);
	EXPECT_EQ(container->getItems().size(), (unsigned int) 1);
}

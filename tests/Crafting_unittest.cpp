#include "Item/Crafting/Crafting.h"
#include "Item/Weapon.h"
#include "Item/Tool.h"
#include "Item/Container.h"
#include "Item/ItemUtils.h"
#include <boost/test/unit_test.hpp>
#include <memory>

BOOST_AUTO_TEST_SUITE(Crafting)

BOOST_AUTO_TEST_CASE(CraftTool)
{/*
	Utils::loadPlugins();
	auto individual = std::make_shared<Actor::Individual>("TestIndividaul", Profession::BAKER);
	auto item = std::make_shared<Item::Food<Item::BREAD>>();
	auto wheat = std::make_shared<Item::Food<Item::WHEAT>>();

	//Add required items to individual inventory
	individual->addItem(wheat);

	//Use up items
	EXPECT_TRUE(Item::Crafting::createItem<Item::Food<Item::BREAD>>(individual) != nullptr);

	//Test that items are removed
	EXPECT_TRUE(Item::Crafting::createItem<Item::Food<Item::BREAD>>(individual) == nullptr);

	//Test that items are required
	EXPECT_TRUE(Item::Crafting::createItem<Item::Container<Item::HOUSE>>(individual) == nullptr);*/
}

BOOST_AUTO_TEST_SUITE_END()

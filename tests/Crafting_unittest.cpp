#include "gtest/gtest.h"
#include "Item/Crafting/Crafting.h"
#include "Item/Weapon.h"
#include "Item/Tool.h"
#include "Item/Container.h"
#include "Individual/SimpleProfession.h"
#include "Item/ItemUtils.h"

#include <memory>

TEST(CraftingTest, CraftTool)
{
	auto individual = std::make_shared<Actor::Individual>("TestIndividaul", Profession::BAKER);
	auto item = std::make_shared<Item::Food<Item::BREAD>>();
	auto wheat = std::make_shared<Item::Food<Item::WHEAT>>();

	individual->addItem(wheat);

	//EXPECT_TRUE(Item::isEnumType<Item::FOOD>(item, Item::Food::BREAD));
	EXPECT_TRUE(Item::Crafting::createItem<Item::Food<Item::BREAD>>(individual) != nullptr);
	EXPECT_TRUE(Item::Crafting::createItem<Item::Container<Item::HOUSE>>(individual) == nullptr);
}

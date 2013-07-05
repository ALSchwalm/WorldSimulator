#include "gtest/gtest.h"
#include "Item/Crafting/Crafting.h"
#include "Item/Weapon.h"
#include "Item/Tool.h"
#include "Individual/SimpleIndividual.h"
#include "Item/ItemUtils.h"

#include <memory>

TEST(CraftingTest, CraftTool)
{
	auto individual = std::make_shared<Individual::Baker>("TestIndividaul");
	auto item = std::make_shared<Item::Food>(Item::BREAD);
	auto wheat = std::make_shared<Item::Food>(Item::WHEAT);

	individual->addItem(wheat);

	EXPECT_TRUE(Item::isEnumType<Item::FOOD>(item, Item::FoodType::BREAD));
	EXPECT_TRUE(Item::Crafting::createItem<Item::Food>(Item::BREAD, individual) != nullptr);
	EXPECT_TRUE(Item::Crafting::createItem<Item::Tool>(Item::PLOW, individual) == nullptr);
}

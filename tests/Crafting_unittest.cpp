#include "gtest/gtest.h"
#include "Item/Crafting/Crafting.h"
#include "Item/Weapon.h"
#include "Item/Tool.h"
#include "Individual/SimpleIndividual.h"

#include <memory>

TEST(CraftingTest, CraftTool)
{
	auto individual = std::make_shared<Individual::Baker>("TestIndividaul");
	EXPECT_TRUE(Item::Crafting::createItem<Item::Food>(Item::BREAD, individual) != nullptr);
}

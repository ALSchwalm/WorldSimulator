
#include "Item/BaseItem.h"
#include "Item/Weapon.h"

#include "gtest/gtest.h"


TEST(ItemTest, HasAttribute)
{

	auto item = std::make_shared<Item::Weapon>("TestWeapon");

	item->setAttribute("old");

	EXPECT_TRUE(item->hasAttribute("old"));
	EXPECT_FALSE(item->hasAttribute("other"));
}

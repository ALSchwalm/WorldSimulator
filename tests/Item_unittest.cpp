
#include <limits.h>
#include "Item/BaseItem.h"
#include "Item/Weapon.h"

#include "gtest/gtest.h"


// Tests factorial of negative numbers.
TEST(ItemTest, HasAttribute) {
	// This test is named "Negative", and belongs to the "FactorialTest"
	// test case.
	auto i = std::make_shared<Item::Weapon>("TestWeapon");

	i->setAttribute("old");

	EXPECT_TRUE(i->hasAttribute("old"));
	EXPECT_FALSE(i->hasAttribute("other"));
}

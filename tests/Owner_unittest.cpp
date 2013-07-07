#include "Item/Weapon.h"
#include "Individual/SimpleIndividual.h"
#include "gtest/gtest.h"


TEST(OwnerTest, Comparison)
{
	auto individual = std::make_shared<Individual::Baker>("TestIndividual");
	auto item = std::make_shared<Item::Weapon<Item::SWORD>>("TestWeapon", individual);

	EXPECT_TRUE(item->getOwner() == individual);
	EXPECT_FALSE(item->getOwner() != individual);

}

#include "Item/Weapon.h"
#include "Individual/SimpleProfession.h"
#include "Individual/Individual.h"
#include "gtest/gtest.h"


TEST(OwnerTest, Comparison)
{
	auto individual = std::make_shared<Actor::Individual>("TestIndividual");
	auto item = std::make_shared<Item::Weapon<Item::SWORD>>("TestWeapon", individual);

	EXPECT_TRUE(item->getOwner() == individual);
	EXPECT_FALSE(item->getOwner() != individual);

}

#include "Item/Weapon.h"
#include "Profession/SimpleProfession.h"
#include "Actor/Individual.h"
#include "gtest/gtest.h"


TEST(OwnerTest, Comparison)
{
	auto individual = std::make_shared<Actor::Individual>("TestIndividual", Profession::BAKER);
	auto item = std::make_shared<Item::Weapon<Item::SWORD>>("TestWeapon", individual);

	EXPECT_TRUE(item->getOwner() == individual);
	EXPECT_FALSE(item->getOwner() != individual);

}

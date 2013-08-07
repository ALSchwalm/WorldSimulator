#include "Item/ItemFactory.h"
#include "Profession/SimpleProfession.h"
#include "Actor/Individual.h"
#include "gtest/gtest.h"


TEST(OwnerTest, Comparison)
{
	auto individual = std::make_shared<Actor::Individual>("TestIndividual", Profession::BAKER);
	auto item = Item::itemFactories[0]->make();

	EXPECT_TRUE(item->getOwner() == individual);
	EXPECT_FALSE(item->getOwner() != individual);

}

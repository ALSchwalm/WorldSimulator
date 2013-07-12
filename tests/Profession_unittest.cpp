#include "Item/Weapon.h"
#include "Profession/SimpleProfession.h"
#include "Actor/Individual.h"
#include "gtest/gtest.h"


TEST(ProfessionTest, InitialItems)
{
    auto individual = std::make_shared<Actor::Individual>("TestIndividual", Profession::BAKER);

    std::vector<Item::Item_ptr> items;

    auto newItems = individual->getInitialItems();

    items.insert(items.end(),newItems.begin(), newItems.end());

    EXPECT_TRUE(!items.empty());

}

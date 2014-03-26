#include "Item/Weapon.h"
#include "Actor/Individual.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Profession)

BOOST_AUTO_TEST_CASE(InitialItems)
{
    auto individual = std::make_shared<Actor::Individual>("TestIndividual");

    std::vector<Item::Item_ptr> items;

    //auto newItems = individual->getInitialItems();

    //items.insert(items.end(),newItems.begin(), newItems.end());

    //BOOST_CHECK(!items.empty());

}

BOOST_AUTO_TEST_SUITE_END()

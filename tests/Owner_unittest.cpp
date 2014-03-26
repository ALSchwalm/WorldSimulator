#include "Actor/Individual.h"
#include "Item/Weapon.h"
#include "ItemImpl.h"

#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Owner)

BOOST_AUTO_TEST_CASE(OwnerTest)
{
    auto individual = std::make_shared<Actor::Individual>("TestIndividual");
	auto item = std::make_shared<Test::ItemImpl<Item::BaseWeapon>>("ID");
        item->setOwner(individual);

	BOOST_CHECK(item->getOwner() == individual);
}

BOOST_AUTO_TEST_SUITE_END()

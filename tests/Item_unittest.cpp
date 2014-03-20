
#include "Item/BaseItem.h"
#include "Item/ItemFactory.h"
#include "Item/Container.h"
#include "Item/Weapon.h"
#include "Location/BaseLocation.h"
#include "Location/Village.h"
#include "Location/World.h"
#include "Location/Location.h"
#include "ItemImpl.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Item)

BOOST_AUTO_TEST_CASE(HasAttribute)
{
    auto item = std::make_shared<Test::ItemImpl<Item::BaseWeapon>>("ID");
    item->setAttribute("old", true);

    BOOST_CHECK(item->hasAttribute("old"));
    BOOST_CHECK(!item->hasAttribute("other"));
}


BOOST_AUTO_TEST_CASE(Container)
{
    auto container = std::make_shared<Test::ItemImpl<Item::BaseContainer>>("ID");
    auto item = std::make_shared<Test::ItemImpl<Item::BaseWeapon>>("ID");

    container->addItem(item);
    Location::addLocations(Location::World::getInstance(), container);

    BOOST_CHECK_EQUAL(container->getLocations().size(), 1u);
    BOOST_CHECK_EQUAL(container->getItems().size(),  1u);
}

BOOST_AUTO_TEST_SUITE_END()

#include "Location/BaseLocation.h"
#include "Location/Village.h"
#include "Location/World.h"
#include "Location/Location.h"
#include "Item/Weapon.h"
#include "ItemImpl.h"

#include <algorithm>
#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Location)

BOOST_AUTO_TEST_CASE(HasAttribute)
{
    auto location = std::make_shared<Location::Village>("TestVillage");

    location->setAttribute("test");

    BOOST_CHECK(location->hasAttribute("test"));
    BOOST_CHECK(!location->hasAttribute("other"));
}

BOOST_AUTO_TEST_CASE(AddItems)
{

    auto location = std::make_shared<Location::Village>("TestVillage");
    auto item = std::make_shared<Test::ItemImpl<Item::BaseWeapon>>("ID");
    auto item2 = std::make_shared<Test::ItemImpl<Item::BaseWeapon>>("ID");

    location->addItem(item);

    BOOST_CHECK_EQUAL(std::count(location->getItems().begin(), location->getItems().end(), item), 1 );
    BOOST_CHECK(std::count(location->getItems().begin(), location->getItems().end(), item2) == 0);
}

BOOST_AUTO_TEST_CASE(RemoveItems)
{

    auto location = std::make_shared<Location::Village>("TestVillage");
    auto item = std::make_shared<Test::ItemImpl<Item::BaseWeapon>>("ID");
    auto item2 = std::make_shared<Test::ItemImpl<Item::BaseWeapon>>("ID");

    location->addItem(item);

    BOOST_CHECK(location->removeItem(item));
    BOOST_CHECK(!location->removeItem(item));
    BOOST_CHECK(!location->removeItem(item2));
}

BOOST_AUTO_TEST_CASE(AddLocationStandard)
{

    auto location = std::make_shared<Location::Village>("TestVillage");
    auto location2 = std::make_shared<Location::Village>("TestVillage2");

    Location::addLocations(location, location2);

    BOOST_CHECK_EQUAL(std::count(location->getLocations().begin(), location->getLocations().end(), location2), 1);
    BOOST_CHECK_EQUAL(std::count(location2->getLocations().begin(), location->getLocations().end(), location), 1);
    BOOST_CHECK_EQUAL(std::count(location->getLocations().begin(),
                                 location->getLocations().end(), location), 0);

    BOOST_CHECK_EQUAL(std::count(location2->getLocations().begin(),
                                 location->getLocations().end(), location2), 0);
}

BOOST_AUTO_TEST_CASE(AddLocationWorld)
{

    auto location = std::make_shared<Location::Village>("TestVillage");

    Location::addLocations(Location::World::getInstance(), location);

    BOOST_CHECK_EQUAL(std::count(location->getLocations().begin(),
                                 location->getLocations().end(),
                                 Location::World::getInstance()), 1);

    BOOST_CHECK_EQUAL(std::count(Location::World::getInstance()->getLocations().begin(),
                                 Location::World::getInstance()->getLocations().end(),
                                 location), 1);

    BOOST_CHECK_EQUAL(std::count(location->getLocations().begin(), location->getLocations().end(), location), 0);
    BOOST_CHECK_EQUAL(std::count(Location::World::getInstance()->getLocations().begin(),
                                 Location::World::getInstance()->getLocations().end(),
                                 Location::World::getInstance()), 0);
}

BOOST_AUTO_TEST_SUITE_END()

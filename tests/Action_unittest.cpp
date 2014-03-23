#include "Profession/SimpleProfession.h"
#include "Item/Food.h"
#include "Actor/ActorUtils.h"
#include "Action/Task.h"
#include "Action/GoalCreator.h"
#include "Location/Village.h"
#include "Location/Location.h"
#include "Event/EventQueue.h"
#include "ItemImpl.h"

#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Action)

#include <vector>

BOOST_AUTO_TEST_CASE(GetFood)
{
    auto location   = std::make_shared<Location::Village>("TestLocation");
    auto location2  = std::make_shared<Location::Village>("TestLocation2");

    Location::connectLocations(location, location2);

    auto individual = std::make_shared<Actor::Individual>("TestPerson", Profession::BAKER, location, false);

    auto item = std::make_shared<Test::ItemImpl<Item::BaseFood>>("1");
    item->setAttribute("edible", true);
    location2->addItem(item);

    Actor::addGoal<Action::GET_FOOD>(individual, 0);

    BOOST_CHECK(Event::EventQueue::getInstance().getNextEvent() != nullptr);
    BOOST_CHECK(Event::EventQueue::getInstance().getNextEvent()->getEventType() == Event::EventType::MOVE);
}

BOOST_AUTO_TEST_SUITE_END()

#include "Profession/SimpleProfession.h"
#include "Item/BaseItem.h"
#include "Item/Weapon.h"
#include "Actor/ActorUtils.h"
#include "Action/Task.h"
#include "Action/GoalCreator.h"
#include "Location/Village.h"
#include "Location/Location.h"
#include "Event/EventQueue.h"

#include "gtest/gtest.h"

#include <vector>

TEST(ActionTest, GetFood)
{

	auto location   = std::make_shared<Location::Village>("TestLocation");
	auto location2  = std::make_shared<Location::Village>("TestLocation2");

	Location::addLocations(location, location2);

	auto individual = std::make_shared<Actor::Individual>("TestPerson", Profession::BAKER, location, false);

	/*
	 * Goal creation is fully specialized, so to find a Weapon, you must call addGoal
	 * with a shared_ptr<BaseItem>.
	 */
	std::shared_ptr<Item::BaseItem>item = std::make_shared<Item::Weapon<Item::SWORD>>("TestWeapon");

	item->setAttribute("edible");

	location2->addItem(item);

	Actor::addGoal<Action::GET_FOOD>(individual, 0);

	EXPECT_TRUE(Event::EventQueue::getInstance().getNextEvent() != nullptr);
	EXPECT_TRUE(Event::EventQueue::getInstance().getNextEvent()->getEventType() == Event::EventType::MOVE);

}

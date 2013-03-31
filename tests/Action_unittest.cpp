#include "Individual/Person.h"
#include "Item/BaseItem.h"
#include "Item/Weapon.h"
#include "Action/Task.h"
#include "Action/GoalCreator.h"
#include "Location/Village.h"
#include "Event/EventQueue.h"

#include "gtest/gtest.h"

#include <vector>

TEST(ActionTest, GetFood)
{

	auto location   = std::make_shared<Location::Village>(nullptr, "TestLocation");
	auto location2  = std::make_shared<Location::Village>(location, "TestLocation2");

	auto individual = std::make_shared<Individual::Person>("TestPerson", location);
	auto item		= std::make_shared<Item::Weapon>("TestWeapon");

	item->setAttribute("edible");

	location2->addItem(item);

	individual->addGoal(Action::GoalType::GET_FOOD, 0);

	EXPECT_TRUE(Event::EventQueue::getInstance().getNextEvent() != nullptr);
	EXPECT_TRUE(Event::EventQueue::getInstance().getNextEvent()->getEventType() == Event::EventType::MOVE_EVENT);

}

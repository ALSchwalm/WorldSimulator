
#include "Action/GoalCreator.h"
#include "Event/MoveEvent.h"
#include "Event/PickupEvent.h"
#include <cassert>
#include <memory>
#include <algorithm>
#include <unordered_set>

using namespace Action;

GoalCreator & GoalCreator::getInstance()
{
	static GoalCreator g;
	return g;
}

GoalCreator::GoalCreator()
{
}

GoalCreator::~GoalCreator()
{
}

Goal_ptr GoalCreator::createGoal(GoalRequest request,
								Individual::Individual_ptr individual,
								unsigned int priority)
{
	//Create empty goal and fill it once tasks have been determined
	currentGoal = std::make_shared<Action::Goal>(request.goalType, priority);

	switch (request.goalType)
	{
	case GET_FOOD:
	{
		assert (request.item == nullptr);
		assert (request.individual == nullptr);
		assert (request.location == nullptr);
		auto get_food = getFood(individual);
		if (get_food.size() == 0)
			break;
		currentGoal->setTasks(get_food);
		return currentGoal;
		break;
	}

	case GET_ITEM:
	{
		assert (request.item != nullptr);
		assert (request.individual == nullptr);
		assert (request.location == nullptr);
		auto get_item = getItem(individual, request.item);
		if (get_item.size() == 0)
			break;
		currentGoal->setTasks(get_item);
		return currentGoal;
	}

	default:
		std::cerr << "Error: Invalid goalType";
		break;
	}

	//silence compiler warning about no return in non-void
	return nullptr;
}

std::vector<Task_ptr> GoalCreator::getFood(Individual::Individual_ptr individual)
{

	std::vector<std::string> attributeList;
	attributeList.push_back("edible");

	std::vector<Action::Task_ptr> taskList = findItemFromAttributes(individual, attributeList, 5);
	std::reverse(taskList.begin(), taskList.end());
	return taskList;
}

std::vector<Task_ptr> GoalCreator::getItem(Individual::Individual_ptr individual, Item::Item_ptr item)
{
	std::vector<Action::Task_ptr> taskList;

	auto startLocation = individual->getCurrentLocation();
	std::vector<Location::Location_ptr> locationList;

	auto search_result = dijkstra(startLocation, item, 5);
	locationList = search_result.second;

	for (auto location : locationList)
	{
		auto newEvent = std::make_shared<Event::MoveEvent>(individual, location);
		taskList.push_back(std::make_shared<Action::Task>(newEvent, currentGoal));
	}

	auto newEvent = std::make_shared<Event::PickupEvent>(search_result.first, individual);
	taskList.push_back(std::make_shared<Action::Task>(newEvent, currentGoal));

	return taskList;
}

//Returns an empty vector if unable to find item
std::vector<Task_ptr> GoalCreator::findItemFromAttributes(Individual::Individual_ptr individual, std::vector<std::string> attributeList, unsigned int maxDistance)
{

	auto startLocation = individual->getCurrentLocation();
	std::vector<Action::Task_ptr> taskList;
	std::vector<Location::Location_ptr> locationList;

	auto search_result = dijkstra(startLocation, attributeList, maxDistance);

	//Returns an empty vector if unable to find item
	if (!search_result.first)
	{
		return taskList;
	}

	locationList = search_result.second;

	for (auto location : locationList)
	{
		auto newEvent = std::make_shared<Event::MoveEvent>(individual, location);
		taskList.push_back(std::make_shared<Action::Task>(newEvent, currentGoal));
	}

	auto newEvent = std::make_shared<Event::PickupEvent>(search_result.first, individual);
	taskList.push_back(std::make_shared<Action::Task>(newEvent, currentGoal));

	return taskList;
}

//TODO find a way to do this without copying vectors
std::pair<Item::Item_ptr, std::vector<Location::Location_ptr>> GoalCreator::dijkstra(Location::Location_ptr startLocation, std::vector<std::string> attributeList, unsigned int maxDistance)
{
	std::vector<Location::Location_ptr> outputList;
	std::unordered_set<Location::Location_ptr> closedSet;
	std::set<Location::Location_ptr, distance> openSet;

	outputList.push_back(startLocation);
	auto foundItem = getItemFromAttributes(startLocation, attributeList);
	if (foundItem == nullptr)
		closedSet.insert(startLocation);
	else
		return std::make_pair(foundItem, outputList);

	startLocation->cameFrom = nullptr;
	startLocation->distance = 0;

	for (auto location : startLocation->getLocations())
	{
		if (location != nullptr)
		{
			location->cameFrom = startLocation;
			location->distance = 1;
			openSet.insert(location);
		}

	}
	while (openSet.size() > 0)
	{
		auto location = (*openSet.begin());

		foundItem = getItemFromAttributes(location, attributeList);
		if (foundItem != nullptr)
		{
			return std::make_pair(foundItem, traceBack(location));
		}

		for (auto nextLocation : location->getLocations())
		{
			if (nextLocation != nullptr && closedSet.find(nextLocation) == closedSet.end() && location->distance+1 < maxDistance)
			{
				nextLocation->cameFrom = location;
				nextLocation->distance = location->distance+1;
				openSet.insert(nextLocation);
			}
		}
		closedSet.insert(location);
		openSet.erase(location);
	}
	outputList.clear();
	return std::make_pair(nullptr, outputList);

}



//TODO find a way to do this without copying vectors
std::pair<Item::Item_ptr, std::vector<Location::Location_ptr>> GoalCreator::dijkstra(Location::Location_ptr startLocation, Item::Item_ptr item, unsigned int maxDistance)
{
	std::vector<Location::Location_ptr> outputList;
	std::unordered_set<Location::Location_ptr> closedSet;
	std::set<Location::Location_ptr, distance> openSet;

	outputList.push_back(startLocation);

	auto foundItem = std::find(startLocation->getItems().begin(), startLocation->getItems().end(), item);
	if (foundItem == startLocation->getItems().end())
		closedSet.insert(startLocation);
	else
		return std::make_pair(*foundItem, outputList);

	startLocation->cameFrom = nullptr;
	startLocation->distance = 0;

	for (auto location : startLocation->getLocations())
	{
		if (location != nullptr)
		{
			location->cameFrom = startLocation;
			location->distance = 1;
			openSet.insert(location);
		}
	}
	while (openSet.size() > 0)
	{
		auto location = (*openSet.begin());

		foundItem = std::find(location->getItems().begin(), location->getItems().end(), item);
		if (foundItem != location->getItems().end())
		{
			return std::make_pair(*foundItem, traceBack(location));
		}

		for (auto nextLocation : location->getLocations())
		{
			if (nextLocation != nullptr && closedSet.find(nextLocation) == closedSet.end() && location->distance+1 < maxDistance)
			{
				nextLocation->cameFrom = location;
				nextLocation->distance = location->distance+1;
				openSet.insert(nextLocation);
			}
		}
		closedSet.insert(location);
		openSet.erase(location);
	}
	outputList.clear();
	return std::make_pair(nullptr, outputList);

}

std::vector<Location::Location_ptr> GoalCreator::traceBack(Location::Location_ptr l)
{
	std::vector<Location::Location_ptr> outputList;
	outputList.push_back(l);
	while(l->cameFrom != nullptr)
	{
		outputList.push_back(l->cameFrom);
		l = l->cameFrom;
	}
	outputList.push_back(l);
	return outputList;
}


Item::Item_ptr GoalCreator::getItemFromAttributes(Location::Location_ptr location, std::vector<std::string> attributeList)
{
	bool found;
	for ( auto item : location->getItems())
	{
		found = true;
		for ( auto attribute : attributeList)
		{
			if (!item->hasAttribute(attribute))
			{
				found = false;
			}
		}
		if (found)
			return item;
	}
	return nullptr;
}


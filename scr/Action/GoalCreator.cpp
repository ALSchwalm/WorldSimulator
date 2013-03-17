
#include "Action/GoalCreator.h"
#include "Event/MoveEvent.h"
#include <cassert>
#include <memory>
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
	currentGoal = std::make_shared<Action::Goal>(request.goalType, priority);

	switch (request.goalType)
	{
	case GET_FOOD:
		assert (request.item == nullptr);
		assert (request.individual == nullptr);
		assert (request.location == nullptr);
		currentGoal->setTasks(getFood(individual));
		return currentGoal;
		break;
	default:
		std::cerr << "Error: Invalid goalType";
		break;
	}

	//silence compiler warning about no return in non-void
	return nullptr;
}

std::vector<Task_ptr> GoalCreator::getFood(Individual::Individual_ptr individual)
{
	std::vector<Action::Task_ptr> taskList;

	std::vector<std::string> attributeList;
	attributeList.push_back("edible");
	taskList = search(individual, attributeList, 5);

	return taskList;
}

std::vector<Task_ptr> GoalCreator::search(Individual::Individual_ptr individual, std::vector<std::string> attributeList, unsigned int maxDistance)
{

	auto startLocation = individual->getCurrentLocation();
	std::vector<Action::Task_ptr> taskList;
	std::vector<Location::Location_ptr> locationList;

	auto search_result = dijkstra(startLocation, attributeList, maxDistance);
	locationList = search_result.second;

	for (auto location : locationList)
	{
		auto newEvent = std::make_shared<Event::MoveEvent>(individual, location);
		taskList.push_back(std::make_shared<Action::Task>(newEvent, currentGoal));
	}

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
	if (getItemFromAttributes(startLocation, attributeList) == nullptr)
		closedSet.insert(startLocation);
	else
		return std::make_pair(foundItem, outputList);

	for (auto location : startLocation->getLocations())
	{
		location->cameFrom = startLocation;
		location->distance = 1;
		openSet.insert(location);

	}
	while (openSet.size() > 0)
	{
		auto location = (*openSet.begin());
		std::cout << location->getName() << std::endl;

		foundItem = getItemFromAttributes(location, attributeList);
		if (foundItem != nullptr)
		{
			return std::make_pair(foundItem, traceBack(location));
		}

		for (auto nextLocation : location->getLocations())
		{
			if (closedSet.find(nextLocation) == closedSet.end() && location->distance+1 < maxDistance)
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
	return outputList;
}


Item::Item_ptr GoalCreator::getItemFromAttributes(Location::Location_ptr location, std::vector<std::string> attributeList)
{
	std::cout << "searching: " << location->getName() << " with " << location->getItems().size() << " items at " << location.get() << std::endl;
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


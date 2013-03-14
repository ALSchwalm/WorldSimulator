
#include "Action/GoalCreator.h"
#include <cassert>
#include <memory>

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
	switch (request.goalType)
	{
	case GET_FOOD:
		assert (request.item == nullptr);
		assert (request.individual == nullptr);
		assert (request.location == nullptr);
		return std::make_shared<Goal>(getFood(individual), request.goalType, priority);
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
	std::vector<std::string> attributeList;
	attributeList.push_back("edible");
	return search(individual->getCurrentLocation(), attributeList, 5);
}

std::vector<Task_ptr> GoalCreator::search(Location::Location_ptr startLocation, std::vector<std::string> attributeList, unsigned int maxDistance)
{
	std::vector<Location::Location_ptr> locationList;
	locationList.push_back(startLocation);
	locationList = dijkstra(locationList, attributeList, maxDistance);
	if (locationList.size() < 1)
	{
		std::cout << "not found" << std::endl;
	}
	for (auto location : locationList)
	{
		std::cout << location->getName() << std::endl;
	}

}

//TODO find a way to do this without copying vectors
std::vector<Location::Location_ptr> GoalCreator::dijkstra(std::vector<Location::Location_ptr> locationList, std::vector<std::string> attributeList, unsigned int maxDistance)
{
	std::vector<Location::Location_ptr> outputList;
	outputList.push_back(locationList[0]);

	for (auto currentLocation : locationList)
	{
		if ( getItemFromAttributes(currentLocation, attributeList) == nullptr )
		{
			if (currentLocation->distance < maxDistance && currentLocation->getLocations().size() != 0)
			{
				for (auto nextLocation : currentLocation->getLocations())
				{
					nextLocation->distance += 1;
					nextLocation->cameFrom = currentLocation;
					locationList.push_back(nextLocation);
				}
			}
		}
		else
		{
			Location::Location_ptr location = currentLocation;
			while ( location != locationList[0])
			{
				outputList.push_back(location);
				location = location->cameFrom;
			}
			return outputList;
		}

	}
	outputList.clear();
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
				found = false;
		}
		if (found)
			return item;
	}
	return nullptr;
}


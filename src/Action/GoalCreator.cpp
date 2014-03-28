
#include "Action/GoalCreator.h"
#include "Action/Task.h"
#include "Actor/Individual.h"
#include "Event/MoveEvent.h"
#include "Event/PickupEvent.h"
#include <memory>
#include <algorithm>
#include <unordered_set>
#include <set>

namespace Action
{

    namespace GoalCreator {

struct distance
{
    bool operator() ( const Location::Location_ptr& lhs,
                      const Location::Location_ptr& rhs) const
    {
        return lhs->distance < rhs->distance;
    }
};

//Forward declarations
std::vector<Task_ptr> getFood(Actor::Individual_ptr individual, Goal_ptr goal);
std::vector<Task_ptr> getItem(Actor::Individual_ptr individual,
                                Item::Item_ptr item,
                                Goal_ptr goal);


std::vector<Task_ptr> findItemFromAttributes(Actor::Individual_ptr individual,
                                            std::vector<std::string> attributeList,
                                            unsigned int maxDistance,
                                            Goal_ptr goal);

std::vector<Location::Location_ptr> traceBack(Location::Location_ptr l);

std::pair<Item::Item_ptr, std::vector<Location::Location_ptr>> dijkstra(Location::Location_ptr startLocation,
                                                                        std::vector<std::string> attributeList,
                                                                        unsigned int maxDistance);

std::pair<Item::Item_ptr, std::vector<Location::Location_ptr>> dijkstra(Location::Location_ptr startLocation,
                                                                        Item::Item_ptr item,
                                                                        unsigned int maxDistance);

Item::Item_ptr getItemFromAttributes(Location::Location_ptr location,
                                    std::vector<std::string> attributeList);
//End forward declarations


template<>
Goal_ptr createGoal<GoalType::GET_FOOD>(Actor::Individual_ptr individual,
                                        unsigned int priority)
{
    auto currentGoal = std::make_shared<Action::Goal>(GoalType::GET_FOOD,
                                                      individual->getGoalTree(),
                                                      priority);
    auto get_food = getFood(individual, currentGoal);
    if (get_food.size() == 0)
        return nullptr;
    currentGoal->setTasks(get_food);
    return currentGoal;
}

template<>
Goal_ptr createGoal<GoalType::GET_ITEM>(Actor::Individual_ptr individual,
                                        unsigned int priority,
                                        Item::Item_ptr item)
{
    auto currentGoal = std::make_shared<Action::Goal>(GoalType::GET_ITEM,
                                                      individual->getGoalTree(),
                                                      priority);
    auto get_item = getItem(individual, item, currentGoal);
    if (get_item.size() == 0)
        return nullptr;
    currentGoal->setTasks(get_item);
    return currentGoal;
}

std::vector<Task_ptr> getFood(Actor::Individual_ptr individual, Goal_ptr goal)
{

    std::vector<std::string> attributeList;
    attributeList.push_back("edible");

    std::vector<Action::Task_ptr> taskList = findItemFromAttributes(individual,
                                                                    attributeList,
                                                                    5, goal);
    std::reverse(taskList.begin(), taskList.end());
    return taskList;
}

std::vector<Task_ptr> getItem(Actor::Individual_ptr individual,
        Item::Item_ptr item,
        Goal_ptr goal)
{
    std::vector<Action::Task_ptr> taskList;

    auto startLocation = individual->getCurrentLocation();
    std::vector<Location::Location_ptr> locationList;

    auto search_result = dijkstra(startLocation, item, 5);
    locationList = search_result.second;

    for (auto location : locationList)
    {
        auto newEvent = std::make_shared<Event::MoveEvent>(individual, location);
        taskList.push_back(std::make_shared<Action::Task>(newEvent, goal));
    }

    auto newEvent = std::make_shared<Event::PickupEvent>(search_result.first,
                                                         individual);
    taskList.push_back(std::make_shared<Action::Task>(newEvent, goal));

    return taskList;
}

//Returns an empty vector if unable to find item
std::vector<Task_ptr> findItemFromAttributes(Actor::Individual_ptr individual,
                                             std::vector<std::string> attributeList,
                                             unsigned int maxDistance,
                                             Goal_ptr goal)
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
        taskList.push_back(std::make_shared<Action::Task>(newEvent, goal));
    }

    auto newEvent = std::make_shared<Event::PickupEvent>(search_result.first, individual);
    taskList.push_back(std::make_shared<Action::Task>(newEvent, goal));

    return taskList;
}

//TODO find a way to do this without copying vectors
std::pair<Item::Item_ptr, std::vector<Location::Location_ptr>> dijkstra(Location::Location_ptr startLocation, std::vector<std::string> attributeList, unsigned int maxDistance)
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
    while (!openSet.empty())
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
std::pair<Item::Item_ptr, std::vector<Location::Location_ptr>> dijkstra(Location::Location_ptr startLocation, Item::Item_ptr item, unsigned int maxDistance)
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
    while (!openSet.empty())
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

std::vector<Location::Location_ptr> traceBack(Location::Location_ptr l)
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


Item::Item_ptr getItemFromAttributes(Location::Location_ptr location, std::vector<std::string> attributeList)
{
    for ( auto item : location->getItems())
    {
        bool found = true;
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

    }
}

#ifndef GOALCREATOR_H_
#define GOALCREATOR_H_

#include "Action/Goal.h"
#include <vector>
#include <utility>
#include <memory>

namespace Actor
{
    class Individual;
    typedef std::shared_ptr<Individual> Individual_ptr;
}

namespace Location
{
    class BaseLocation;
    typedef std::shared_ptr<BaseLocation> Location_ptr;
}


namespace Action
{

    class GoalCreator
    {

    public:
        static GoalCreator& getInstance();

        template<GoalType g>
        Goal_ptr createGoal(Actor::Individual_ptr individual, unsigned int priority);

        template<GoalType g, typename T>
        Goal_ptr createGoal(Actor::Individual_ptr individual, unsigned int priority, T t);

        template<GoalType g, typename T, typename U>
        Goal_ptr createGoal(Actor::Individual_ptr individual, unsigned int priority, T t, U u);



    private:

        struct distance
        {
            bool operator() ( const Location::Location_ptr& lhs, const Location::Location_ptr& rhs) const;
        };
        std::vector<Task_ptr> getFood(Actor::Individual_ptr individual);
        std::vector<Task_ptr> getItem(Actor::Individual_ptr individual, Item::Item_ptr item);


        std::vector<Task_ptr> findItemFromAttributes(Actor::Individual_ptr individual, std::vector<std::string> attributeList, unsigned int maxDistance);
        std::vector<Location::Location_ptr> traceBack(Location::Location_ptr l);

        std::pair<Item::Item_ptr, std::vector<Location::Location_ptr>> dijkstra(Location::Location_ptr startLocation, std::vector<std::string> attributeList, unsigned int maxDistance);
        std::pair<Item::Item_ptr, std::vector<Location::Location_ptr>> dijkstra(Location::Location_ptr startLocation, Item::Item_ptr item, unsigned int maxDistance);

        Item::Item_ptr getItemFromAttributes(Location::Location_ptr location, std::vector<std::string> attributeList);

        GoalCreator();
        ~GoalCreator();

        Action::Goal_ptr currentGoal;

    };

}

#endif

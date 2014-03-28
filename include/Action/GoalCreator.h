#ifndef GOALCREATOR_H_
#define GOALCREATOR_H_

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
    enum class GoalType;
    class Goal;
    typedef std::shared_ptr<Goal> Goal_ptr;

    namespace GoalCreator
    {

        template<GoalType g, typename... T>
        Goal_ptr createGoal(Actor::Individual_ptr individual, unsigned int priority, T... args);

    };

}

#endif

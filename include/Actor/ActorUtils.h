
#ifndef ACTORUTILS_H_
#define ACTORUTILS_H_

#include "Actor/Individual.h"
#include <vector>
#include <memory>

namespace Location
{
    class BaseLocation;
    typedef std::shared_ptr<BaseLocation> Location_ptr;
}

namespace Actor
{
    const std::vector<Individual_ptr> createFamily(unsigned int size=4,
                                                   Location::Location_ptr l=nullptr);

    /*
    * Goal creation is started here, then passed to the goal tree. The goal tree
    * then calls the goalCreator, which fully specializes function templates. This allows
    * compile-time checking of the validity of the template/function arguments. For example
    * it is not possible to create a GET_FOOD goal, with a BaseEvent type.
    */
    template<Action::GoalType g, typename... U>
    void addGoal(Individual_ptr i, unsigned int _priority, U&&... args)
    {
        i->getGoalTree()->addGoal<g>(i, _priority, std::forward<U>(args)...);
    }
}

#endif

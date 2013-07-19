
#ifndef ACTORUTILS_H_
#define ACTORUTILS_H_

#include "Actor/Individual.h"
#include "Profession/Profession.h"
#include "Location/BaseLocation.h"
#include <vector>

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
    void addGoal(Individual_ptr i, unsigned int _priority, U... args)
    {
        i->getGoalTree()->addGoal<g, U...>(i, _priority, args...);
    }
}

#endif

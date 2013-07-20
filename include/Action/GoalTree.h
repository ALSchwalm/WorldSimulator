#ifndef GOALTREE_H_
#define GOALTREE_H_

#include "Action/Goal.h"
#include "Action/GoalCreator.h"
#include <set>
#include <memory>
#include <functional>
#include <utility>

namespace Action
{

    class GoalTree
    {
    public:
        GoalTree();
        ~GoalTree();

        GoalTree& operator=(GoalTree&) = delete;

        void execute();
        void goalFinished(bool success);
        void interrupt();


        template<GoalType g, typename... U>
        void addGoal(Actor::Individual_ptr i, unsigned int _priority, U&&... args)
        {
            auto func = std::bind(Action::GoalCreator::createGoal<g>, i, _priority, std::forward<U>(args)...);
            insertGoal(GoalWrapper(func, _priority));
        }

    private:

        struct GoalWrapper
        {
            GoalWrapper(std::function<Goal_ptr()> fn,  unsigned int _priority) :
                goalFunction(fn),
                priority(_priority){}

            std::function<Goal_ptr()> goalFunction;
            unsigned int priority;
        };

        void insertGoal(GoalWrapper);

        struct priority
        {
            bool operator() ( const GoalWrapper & lhs, const GoalWrapper & rhs) const {
                return lhs.priority < rhs.priority;
            }
        };

        Individual::Individual_ptr owner; //Individual who has this goalTree

        Goal_ptr currentGoal;
        std::set<GoalWrapper, priority> goalHeap;

    };

}

#endif

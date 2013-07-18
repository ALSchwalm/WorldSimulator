#ifndef GOALTREE_H_
#define GOALTREE_H_

#include <set>
#include <memory>
#include "Action/Goal.h"
#include "Action/GoalCreator.h"


namespace Action
{

    class GoalTree
    {
    public:
        GoalTree(Actor::Individual_ptr);
        ~GoalTree();

        GoalTree& operator=(GoalTree&) = delete;

        void execute();
        void goalFinished(bool success);
        void interrupt();

        template<GoalType g>
        void addGoal(unsigned int _priority)
        {
            auto func = [&](){ return Action::GoalCreator::getInstance().createGoal<g>(owner, _priority); };
            insertGoal(GoalWrapper(func, _priority));
        }

        template<GoalType g, typename T>
        void addGoal(unsigned int _priority, T t)
        {
            auto func = [&](){ return GoalCreator::getInstance().createGoal<g, T>(owner, _priority, t);};
            insertGoal(GoalWrapper(func, _priority));
        }

        template<GoalType g, typename T, typename U>
        void addGoal(T t, U u,unsigned int _priority)
        {
            auto func = [&](){ return GoalCreator::getInstance().createGoal<g, T, U>(owner, _priority, t, u); };
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

#ifndef GOAL_H_
#define GOAL_H_

#include <vector>
#include <memory>
#include "Item/BaseItem.h"

namespace Actor
{
  class Individual;
  typedef std::shared_ptr<Individual> Individual_ptr;
}


namespace Action
{
    class GoalTree;
    class Task;
    typedef std::shared_ptr<Task> Task_ptr;


    enum class GoalType
    {
        GET_FOOD,
        GET_ITEM,

        NUM_OF_GOALS
    };

    using Type = GoalType;

    class Goal
    {

    public:
        Goal(GoalType g, GoalTree* source, unsigned int p = 0);
        Goal(std::vector<Task_ptr>, GoalType g,  GoalTree* source, unsigned int p = 0);

        Goal(const Goal&) = delete;
        Goal& operator=(const Goal&) = delete;

        void execute();
        void taskFinished(bool success);
        void interrupt(); //TODO return bool for uninterruptable tasks?

        void setTasks(std::vector<Task_ptr> _taskList){taskList = _taskList;}

        unsigned int getPriority() {return priority;}


    private:
        std::vector<Task_ptr> taskList;
        GoalType goalType;
        GoalTree* tree;
        unsigned int priority;

    };

    typedef std::shared_ptr<Goal> Goal_ptr;
}

#endif

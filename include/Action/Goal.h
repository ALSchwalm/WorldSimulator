#ifndef GOAL_H_
#define GOAL_H_

#include <vector>
#include <memory>
#include "Action/Task.h"
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


    enum GoalType
    {
        GET_FOOD,
        GET_ITEM,

        NUM_OF_GOALS
    };

    class Goal
    {

    public:
        Goal(GoalType g, unsigned int p = 0);
        Goal(std::vector<Task_ptr>, GoalType g, unsigned int p = 0);

        Goal(const Goal&) = delete;
        Goal& operator=(const Goal&) = delete;

        bool execute();
        void taskFinished();

        void setTasks(std::vector<Task_ptr> _taskList){taskList = _taskList;}

        unsigned int getPriority() {return priority;}
        void interrupt(); //TODO return bool for uninterruptable tasks?

    private:
        std::vector<Task_ptr> taskList;
        GoalType goalType;
        unsigned int priority;
        std::shared_ptr<GoalTree> tree;

    };

    typedef std::shared_ptr<Goal> Goal_ptr;
}

#endif

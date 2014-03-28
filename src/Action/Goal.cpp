#include "Action/Task.h"
#include "Action/Goal.h"
#include "Action/GoalTree.h"

using namespace Action;

Goal::Goal(GoalType _goalType,  GoalTree* source, unsigned int _priority) :
        goalType(_goalType),
        tree(source),
        priority(_priority)
{
}


Goal::Goal(std::vector<Task_ptr> _taskList,
        GoalType _goalType,
        GoalTree* source,
        unsigned int _priority) :
        taskList(_taskList),
        goalType(_goalType),
        tree(source),
        priority(_priority)
{
}

void Goal::execute()
{
    if (!taskList.empty())
       taskList.back()->run();
    else
        tree->goalFinished(true);
}

void Goal::taskFinished(bool success)
{
    if (success) {
        taskList.pop_back();
        this->execute();
    }
    else
    {
        tree->goalFinished(false);
    }
}

void Goal::interrupt()
{
    taskList.back()->interrupt();
}

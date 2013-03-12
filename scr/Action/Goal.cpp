
#include "Action/Goal.h"

using namespace Action;

Goal::Goal(std::vector<Task_ptr> _taskList, GoalType _goalType, unsigned int _priority) :
		taskList(_taskList),
		goalType(_goalType),
		priority(_priority)
{

}

bool Goal::execute()
{
	if (taskList.back()->run() )
	{
		return true;
	}
	return false;

}

void Goal::taskFinished()
{

}

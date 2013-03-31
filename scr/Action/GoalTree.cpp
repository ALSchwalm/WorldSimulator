
#include "Action/GoalTree.h"
#include "Action/GoalCreator.h"
#include <cassert>

#include <iostream> //TODO remove this

using namespace Action;

GoalTree::GoalTree(Individual::Individual_ptr _individual) :
		owner(_individual)
{

}

GoalTree::~GoalTree()
{

}

void GoalTree::execute()
{
	GoalWrapper temp = (*goalHeap.begin());
	currentGoal = GoalCreator::getInstance().createGoal(temp.goalRequest, owner, temp.priority);

	goalHeap.erase(goalHeap.begin());

	assert(currentGoal != nullptr);

	currentGoal->execute();
}

void GoalTree::goalFinished()
{
	if (goalHeap.begin() != goalHeap.end())
		execute();

}

void GoalTree::addGoal(GoalRequest _goalRequest,  unsigned int _priority)
{
	if (goalHeap.size() != 0)
	{
		if (_priority > currentGoal->getPriority())
		{
			goalHeap.insert(GoalWrapper(_goalRequest, _priority));

			//Interrupt will call up to goalFinished, which will execute the new goalHeap.begin()
			currentGoal->interrupt();

			std::cout << "interrupted" << std::endl;
		}
	}
	else
	{
		goalHeap.insert(GoalWrapper(_goalRequest, _priority));
		execute();
	}
}

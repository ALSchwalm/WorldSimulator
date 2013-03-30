
#include "Action/GoalTree.h"
#include <cassert>

#include <iostream> //TODO remove this

using namespace Action;

GoalTree::GoalTree()
{

}

GoalTree::~GoalTree()
{

}

void GoalTree::execute()
{
	(*goalHeap.begin())->execute();
}

void GoalTree::goalFinished()
{
	//TODO This may need to be goals.back() or goals.end() - 1
	goalHeap.erase(goalHeap.begin());
	if (goalHeap.begin() != goalHeap.end())
		(*goalHeap.begin())->execute();

}

void GoalTree::addGoal(Goal_ptr goal)
{
	assert(goal != nullptr);

	if (goalHeap.size() != 0)
	{
		if (goal->getPriority() > (*goalHeap.begin())->getPriority())
		{
			auto temp = *goalHeap.begin();
			goalHeap.insert(goal);
			temp->interrupt();
			std::cout << "interrupted" << std::endl;
		}
	}
	else
	{
		goalHeap.insert(goal);
		execute();
	}
}

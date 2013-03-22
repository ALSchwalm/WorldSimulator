
#include "Action/GoalTree.h"

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

}

void GoalTree::addGoal(Goal_ptr goal)
{
	if (goal->getPriority() > (*goalHeap.begin())->getPriority() ) //FIXME goalHeap may be empty
		goalHeap.insert(goal);
}

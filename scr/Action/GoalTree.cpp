
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
	goals.back()->execute();
}

void GoalTree::goalFinished()
{
	//TODO This may need to be goals.back() or goals.end() - 1
	goals.erase(goals.end());
}

void GoalTree::addGoal(Goal_ptr goal)
{
	//TODO This should be based on priority
	goals.push_back(goal);
}

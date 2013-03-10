
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
	(*goals.begin())->execute();
}

void GoalTree::goalFinished()
{
	//TODO This may need to be goals.back() or goals.end() - 1
	goals.erase(goals.begin());
}

void GoalTree::addGoal(Goal_ptr goal)
{
	goals.insert(goal);
}

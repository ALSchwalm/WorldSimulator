
#include "Action/GoalTree.h"

#include "Action/Goal.h"
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
    currentGoal = temp.goalFunction();

    goalHeap.erase(goalHeap.begin());

    assert(currentGoal != nullptr);

    currentGoal->execute();
}

void GoalTree::goalFinished()
{
    if (goalHeap.begin() != goalHeap.end())
        execute();
}


void GoalTree::insertGoal(GoalWrapper g)
{
    if (goalHeap.size() != 0)
    {
        if (g.priority > currentGoal->getPriority())
        {
            goalHeap.insert(g);
            currentGoal->interrupt();
            std::cout << "interrupted" << std::endl;
        }
        else
        {
            goalHeap.insert(g);
        }
    }
    else
    {
        goalHeap.insert(g);
        execute();
    }
}

void GoalTree::interrupt()
{
    currentGoal->interrupt();
}


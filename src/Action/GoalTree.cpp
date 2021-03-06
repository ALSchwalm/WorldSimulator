
#include "Action/GoalTree.h"

#include "Action/Goal.h"
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
    GoalWrapper temp = (*goalHeap.begin());

    //Call the goalWrapper function to create the actual goal
    currentGoal = temp.goalFunction();

    assert(currentGoal != nullptr);

    currentGoal->execute();
}

void GoalTree::goalFinished(bool success)
{
    if (success)
    {
        goalHeap.erase(goalHeap.begin());
    }

    if (goalHeap.begin() != goalHeap.end())
    {
        execute();
    }
}


void GoalTree::insertGoal(GoalWrapper g)
{
    if (!goalHeap.empty())
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


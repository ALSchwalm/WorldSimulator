
#include "Action/GoalCreator.h"
#include <cassert>

using namespace Action;

GoalCreator & GoalCreator::getInstance()
{
	static GoalCreator g;
	return g;
}

GoalCreator::GoalCreator()
{
}

GoalCreator::~GoalCreator()
{
}

std::vector<Task_ptr> GoalCreator::createGoal(GoalRequest request,
												Individual::Individual_ptr individual,
												unsigned int piority)
{
	switch (request.goalType)
	{
	case GET_FOOD:
		assert (request.item == nullptr);
		assert (request.individual == nullptr);
		assert (request.location == nullptr);
		return getFood(individual);
		break;
	default:
		std::cerr << "Invalid goalType";
		break;
	}

	//silence compiler warning about no return in non-void
	return *(new std::vector<Task_ptr>);
}

std::vector<Task_ptr> GoalCreator::getFood(Individual::Individual_ptr individual)
{

}


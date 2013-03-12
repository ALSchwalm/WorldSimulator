#ifndef GOALCREATOR_H_
#define GOALCREATOR_H_

#include "Action/Goal.h"
#include "Individual/BaseIndividual.h"
#include <vector>

namespace Action
{

	class GoalCreator
	{

	public:
		static GoalCreator & getInstance();

		//Implicit conversion from GoalType to GoalRequest, can be called with Action::GoalType::{type}
		std::vector<Task_ptr> createGoal(GoalRequest, Individual::Individual_ptr, unsigned int priority);

		std::vector<Task_ptr> getFood(Individual::Individual_ptr individual);

	private:
		GoalCreator();
		~GoalCreator();

	};

}

#endif

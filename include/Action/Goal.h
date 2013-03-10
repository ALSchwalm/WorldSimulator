#ifndef GOAL_H_
#define GOAL_H_

#include <vector>
#include <memory>
#include "Action/Task.h"

namespace Action
{
	class GoalTree;
	class Task;
	typedef std::shared_ptr<Task> Task_ptr;


	enum GoalType
	{
		GET_FOOD,

		NUM_OF_GOALS
	};

	//This is not a base class
	class Goal
	{

	public:
		Goal(std::vector<Task_ptr>, GoalType g, unsigned int p = 0);

		bool execute();
		void taskFinished();

		unsigned int getPriority() {return priority;}

	private:
		unsigned int priority;
		GoalType goalType;
		std::shared_ptr<GoalTree> tree;
		std::vector<Task_ptr> taskList;

	};

	typedef std::shared_ptr<Goal> Goal_ptr;
}

#endif

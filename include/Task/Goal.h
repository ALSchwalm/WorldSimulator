#ifndef GOAL_H_
#define GOAL_H_

#include <vector>
#include <memory>
#include "Task/GoalTree.h"
#include "Task/BaseTask.h"

namespace Task
{
	typedef std::shared_ptr<Goal> Goal_ptr;

	enum GoalType
	{
		GET_FOOD,

		NUM_OF_GOALS
	};

	//This is not a base class
	class Goal
	{

	public:
		Goal(std::vector<Task_ptr>, GoalType g);

		bool execute();

	private:
		GoalType goalType;
		std::shared_ptr<GoalTree> tree;
		std::vector<Task_ptr> taskList;

	};

}

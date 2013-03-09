#ifndef TASKTREE_H_
#define TASKTREE_H_

#include <vector>
#include <memory>
#include "Task/Goal.h"


namespace Task
{

	class GoalTree
	{
	public:
		GoalTree();
		~GoalTree();

		void execute();

	private:
		Goal_ptr currentGoal;
		std::vector<Goal_ptr> goals;


	};

}

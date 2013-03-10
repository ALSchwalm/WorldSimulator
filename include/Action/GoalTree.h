#ifndef GOALTREE_H_
#define GOALTREE_H_

#include <vector>
#include <memory>
#include "Action/Goal.h"


namespace Action
{
	class Goal;
	typedef std::shared_ptr<Goal> Goal_ptr;


	class GoalTree
	{
	public:
		GoalTree();
		~GoalTree();

		void execute();
		void goalFinished();
		void goalInterruped(){};

		void addGoal(Goal_ptr goal);

	private:
		Goal_ptr currentGoal;
		std::vector<Goal_ptr> goals;


	};

}

#endif

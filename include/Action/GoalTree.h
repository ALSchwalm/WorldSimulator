#ifndef GOALTREE_H_
#define GOALTREE_H_

#include <set>
#include <memory>
#include "Action/Goal.h"


namespace Action
{


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

		struct priority
		{
			bool operator() ( const Goal_ptr & lhs, const Goal_ptr & rhs) const {
				return lhs->getPriority() < rhs->getPriority();
			}
		};

		std::set<Goal_ptr, priority> goalHeap;


	};

}

#endif

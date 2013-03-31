#ifndef GOALTREE_H_
#define GOALTREE_H_

#include <set>
#include <memory>
#include "Action/Goal.h"


namespace Action
{
	struct GoalWrapper
	{
		GoalWrapper(GoalRequest _goalReqest,  unsigned int _priority) :
			goalRequest(_goalReqest),
			priority(_priority){}

		GoalRequest goalRequest;
		unsigned int priority;
	};

	class GoalTree
	{
	public:
		GoalTree(Individual::Individual_ptr);
		~GoalTree();

		void execute();
		void goalFinished();
		void goalInterruped(){};

		void addGoal(GoalRequest, unsigned int);

	private:
		struct priority
		{
			bool operator() ( const GoalWrapper & lhs, const GoalWrapper & rhs) const {
				return lhs.priority < rhs.priority;
			}
		};

		Individual::Individual_ptr owner; //Individual who has this goalTree

		Goal_ptr currentGoal;
		std::set<GoalWrapper, priority> goalHeap;


	};

}

#endif

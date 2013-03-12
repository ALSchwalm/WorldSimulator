#ifndef GOAL_H_
#define GOAL_H_

#include <vector>
#include <memory>
#include "Action/Task.h"
#include "Item/BaseItem.h"

namespace Individual
{
	class BaseIndividual;
	typedef std::shared_ptr<BaseIndividual> Individual_ptr;
}

namespace Location
{
	class BaseLocation;
	typedef std::shared_ptr<BaseLocation> Location_ptr;
}



namespace Action
{
	class GoalTree;
	class Task;
	typedef std::shared_ptr<Task> Task_ptr;


	enum GoalType
	{
		GET_FOOD,
		GET_ITEM,

		NUM_OF_GOALS
	};

	class GoalRequest
	{
	public:
		GoalRequest(GoalType g) :
			goalType(g),
			location(nullptr),
			individual(nullptr),
			item(nullptr){}

		GoalType goalType;
		Location::Location_ptr location;
		Individual::Individual_ptr individual;
		Item::Item_ptr item;

	};

	typedef std::shared_ptr<GoalRequest> GoalRequest_ptr;


	//This is not a base class
	class Goal
	{

	public:
		Goal(std::vector<Task_ptr>, GoalType g, unsigned int p = 0);

		bool execute();
		void taskFinished();

		unsigned int getPriority() {return priority;}

	private:
		std::vector<Task_ptr> taskList;
		GoalType goalType;
		unsigned int priority;
		std::shared_ptr<GoalTree> tree;


	};

	typedef std::shared_ptr<Goal> Goal_ptr;
}

#endif

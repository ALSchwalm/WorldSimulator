#ifndef GOALCREATOR_H_
#define GOALCREATOR_H_

#include "Action/Goal.h"
#include "Individual/BaseIndividual.h"
#include "Location/BaseLocation.h"
#include <vector>

namespace Action
{

	class GoalCreator
	{

	public:
		static GoalCreator & getInstance();

		//Implicit conversion from GoalType to GoalRequest, can be called with Action::GoalType::{type}
		Goal_ptr createGoal(GoalRequest, Individual::Individual_ptr, unsigned int priority);


	private:

		std::vector<Task_ptr> search(Location::Location_ptr, std::vector<std::string> attributeList, unsigned int maxDistance);

		std::vector<Location::Location_ptr> dijkstra(std::vector<Location::Location_ptr> locationList, std::vector<std::string> attributeList, unsigned int maxDistance);
		Item::Item_ptr getItemFromAttributes(Location::Location_ptr location, std::vector<std::string> attributeList);
		std::vector<Task_ptr> getFood(Individual::Individual_ptr individual);

		GoalCreator();
		~GoalCreator();

	};

}

#endif

#ifndef GOALCREATOR_H_
#define GOALCREATOR_H_

#include "Action/Goal.h"
#include "Individual/BaseIndividual.h"
#include "Location/BaseLocation.h"
#include <vector>
#include <utility>

namespace Action
{

	class GoalCreator
	{

	public:
		static GoalCreator & getInstance();

		//Implicit conversion from GoalType to GoalRequest, can be called with Action::GoalType::{type}
		Goal_ptr createGoal(GoalRequest, Individual::Individual_ptr, unsigned int priority);


	private:

		struct distance
		{
			bool operator() ( const Location::Location_ptr & lhs, const Location::Location_ptr & rhs) const {
				return lhs->distance < rhs->distance;
			}
		};

		std::vector<Task_ptr> findItemFromAttributes(Individual::Individual_ptr individual, std::vector<std::string> attributeList, unsigned int maxDistance);
		std::vector<Location::Location_ptr> traceBack(Location::Location_ptr l);
		std::pair<Item::Item_ptr, std::vector<Location::Location_ptr>> dijkstra(Location::Location_ptr startLocation, std::vector<std::string> attributeList, unsigned int maxDistance);
		Item::Item_ptr getItemFromAttributes(Location::Location_ptr location, std::vector<std::string> attributeList);
		std::vector<Task_ptr> getFood(Individual::Individual_ptr individual);

		GoalCreator();
		~GoalCreator();

		Action::Goal_ptr currentGoal;

	};

}

#endif

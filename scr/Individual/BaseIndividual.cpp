#include "Individual/BaseIndividual.h"
#include "Action/GoalTree.h"
#include "Relationship/Relationship.h"
#include <algorithm>

using namespace Individual;

bool BaseIndividual::removeItem(Item::Item_ptr i)
{
	if (std::find(items.begin(), items.end(), i) == items.end())
	{
		return false;
	}
	else
	{
		items.erase(std::find(items.begin(), items.end(), i));
		return true;
	}
}

void BaseIndividual::addRelationship(Location::Location_ptr location, Relationship::RelationshipType rel)
{
	LocationRelationshipMap.addRelationship(location, rel);
}

void BaseIndividual::addRelationship(Individual_ptr individual, Relationship::RelationshipType rel)
{
	IndividualRelationshipMap.addRelationship(individual, rel);
}

void BaseIndividual::addGoal(Action::GoalRequest _goalRequest, unsigned int _priority)
{
	goalTree.addGoal(_goalRequest,  _priority);
}

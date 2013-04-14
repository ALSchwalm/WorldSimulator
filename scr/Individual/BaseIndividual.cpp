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

unsigned int BaseIndividual::calculatePriority(Individual_ptr individual, Action::GoalType goalType)
{
	//TODO relationships can be both positive and negative, so size is not a good metric
	if (IndividualRelationshipMap.getRelationships(individual).size() != 0)
		return 10;
	return 0;
}

#include "Actor/Individual.h"
#include "Profession/BaseProfession.h"
#include "Action/GoalTree.h"
#include "Relationship/Relationship.h"
#include <algorithm>
#include <exception>

namespace Actor
{

    const std::vector<Item::Item_ptr> Individual::getInitialItems()
    {
        std::vector<Item::Item_ptr> items;
        profession->addInitialItems(items);
        return items;
    }

    const float Individual::getSkillLevel(Skill::skills s)
    {
        try {
            /*
             * getSkillLevel from profession will return 0.0f if the lookup fails.
             * We can assume, therefore, that the exception must have been generated by the lookup
             * in the player skillMap. So return the professionSkill.
             */

            return skillMap.at(s) + profession->getSkillLevel(s);
        }
        catch (std::exception& e) {
            return profession->getSkillLevel(s);
        }

    }

    bool Individual::removeItem(Item::Item_ptr i)
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

    void Individual::addRelationship(Location::Location_ptr location, Relationship::RelationshipType rel)
    {
        LocationRelationshipMap.addRelationship(location, rel);
    }

    void Individual::addRelationship(Individual_ptr individual, Relationship::RelationshipType rel)
    {
        IndividualRelationshipMap.addRelationship(individual, rel);
    }

    unsigned int Individual::calculatePriority(Individual_ptr individual, Action::GoalType goalType)
    {
        //TODO relationships can be both positive and negative, so size is not a good metric
        if (IndividualRelationshipMap.getRelationships(individual).size() != 0)
            return 10;
        return 0;
    }
}

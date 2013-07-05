#include "Relationship/Relationship.h"
#include "Individual/BaseIndividual.h"

namespace Relationship
{
    void createSymetricRelationship(Individual::Individual_ptr one, Individual::Individual_ptr two, RelationshipType rel)
    {
        one->getIndividualRelationshipMap().addRelationship(two, rel);
        two->getIndividualRelationshipMap().addRelationship(one, rel);
    }

    void createASymetricRelationship(Individual::Individual_ptr one, RelationshipType relOne, Individual::Individual_ptr two, RelationshipType relTwo)
    {
        one->getIndividualRelationshipMap().addRelationship(two, relTwo);
        two->getIndividualRelationshipMap().addRelationship(one, relOne);
    }

    //Warning: this is very slow, do not use often
    template<typename T>
    std::vector<T> RelationshipMap<T>::getInstances(RelationshipType rel)
    {
        std::vector<T> instances;

        for (auto i : relationshipMap)
        {
            if (std::count(i->second.begin(), i->second.end(), rel) != 0)
                instances.push_back(i->first);
        }
        return instances;
    }

}


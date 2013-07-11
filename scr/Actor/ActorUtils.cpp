
#include "Actor/ActorUtils.h"
#include "Relationship/Relationship.h"
#include "Utils/Markov.h"
#include <memory>

namespace Actor
{

    const std::vector<Individual_ptr> createFamily(unsigned int size, Location::Location_ptr l)
    {
        std::vector<Individual_ptr> family;
        if (size==0)
            return family;

        //Construct father
        family.push_back(std::make_shared<Individual>(Utils::Markov::getInstance().getProperWord(),
                                                    Profession::BAKER,
                                                    l,
                                                    true));
        --size;
        if (size > 0)
        {
            //Construct mother
            family.push_back(std::make_shared<Individual>(Utils::Markov::getInstance().getProperWord(),
                                                        Profession::BAKER,
                                                        l,
                                                        false));

            Relationship::createASymetricRelationship(family[0],
                                                        Relationship::HUSBAND,
                                                        family[1],
                                                        Relationship::WIFE);

            --size;
        }
        else
        {
            return family;
        }

        for (; size > 0; --size){
            //Construct children
            auto child = std::make_shared<Individual>(Utils::Markov::getInstance().getProperWord(),
                                                    Profession::BAKER, /*TODO change to child*/
                                                    l,
                                                    rand()%2);
            family.push_back(child);

            Relationship::createASymetricRelationship(family[0],
                                                        Relationship::FATHER,
                                                        child,
                                                        Relationship::CHILD);

            Relationship::createASymetricRelationship(family[1],
                                                        Relationship::MOTHER,
                                                        child,
                                                        Relationship::CHILD);
        }

        if (l)
        {
            for (auto member : family)
            {
                l->addIndividual(member);
            }
        }

        return family;

    }
}

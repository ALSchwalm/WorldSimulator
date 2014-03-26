
#include "Actor/ActorUtils.h"
#include "Relationship/Relationship.h"
#include "Profession/ProfessionUtils.h"
#include "Utils/Markov.h"
#include "Utils/Utils.h"
#include <memory>

namespace Actor
{

    const std::vector<Individual_ptr> createFamily(unsigned int size, Location::Location_ptr l)
    {
        std::vector<Individual_ptr> family;
        if (size==0)
            return family;

        std::string familyName = Utils::Markov::getInstance().getProperWord();

        //Construct father
        family.push_back(std::make_shared<Individual>(Utils::Markov::getInstance().getIndividualName(familyName),
                                                      l,
                                                      Profession::getRandomProfession(),
                                                      true));
        --size;
        if (size > 0)
        {
            //Construct mother
            family.push_back(std::make_shared<Individual>(Utils::Markov::getInstance().getIndividualName(familyName),
                                                          l,
                                                          Profession::getRandomProfession(),
                                                          false));

            Relationship::createASymetricRelationship(family[0],
                                                      Relationship::HUSBAND,
                                                      family[1],
                                                      Relationship::WIFE);
            --size;
        }

        for (; size > 0; --size){
            //Construct children
            auto child = std::make_shared<Individual>(Utils::Markov::getInstance().getIndividualName(familyName),
                                                      l,
                                                      Profession::getRandomProfession(),
                                                      Utils::uniform(0, 2));
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

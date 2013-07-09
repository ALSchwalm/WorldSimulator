
#include "Individual/Individual.h"
#include "Individual/BaseProfession.h"
#include "Individual/SimpleProfession.h"
#include "Utils/Config.h"

namespace Profession
{

    const unsigned int ProfessionValues[]
    {
        Utils::Config::getInstance().getValue("OccupationRate", "BAKER_RATE")
    };

    static_assert(sizeof(ProfessionValues)/sizeof(ProfessionValues[0]) == NUM_OF_PROFESSIONS,
            "IndividualType not given value in IndividualValues.");


    static std::shared_ptr<BaseProfession> createIndividualFromType(ProfessionType _type)
    {
        switch(_type)
        {
        case BAKER:
            return std::make_shared<Baker>();
        default:
            throw("Attempt to create individual from invalid enum.");
            return nullptr;
        }
    }

    std::shared_ptr<BaseProfession> getRandomProfession()
    {
        ProfessionType profession = static_cast<ProfessionType>(rand()%NUM_OF_PROFESSIONS);
        return createIndividualFromType(profession);
    }
/*
    std::vector<Item::Item_ptr> getInitialItems(std::shared_ptr<BaseIndividual> individual)
    {
        std::vector<Item::Item_ptr> items;
        individual->addInitialItems(items);
        for (auto item : items)
            item->setOwner(individual);
        return items;
    }
*/
}

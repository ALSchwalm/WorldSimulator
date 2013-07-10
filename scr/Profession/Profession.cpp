
#include "Actor/Individual.h"
#include "Profession/BaseProfession.h"
#include "Profession/SimpleProfession.h"
#include "Utils/Config.h"

namespace Profession
{

    const unsigned int ProfessionValues[]
    {
        Utils::Config::getInstance().getValue("OccupationRate", "BAKER_RATE")
    };

    static_assert(sizeof(ProfessionValues)/sizeof(ProfessionValues[0]) == NUM_OF_PROFESSIONS,
            "IndividualType not given value in IndividualValues.");


    std::shared_ptr<BaseProfession> createProfessionFromType(ProfessionType _type)
    {
        /*
         * Do not set a default case to cause a compiler warning if a case is unhandled
         */
        switch(_type)
        {
        case BAKER:
            return std::make_shared<Baker>();

        case NUM_OF_PROFESSIONS:
            throw("Attempt to create individual from invalid enum.");
            return nullptr;

        case PROFESSION_ERROR:
            throw("Attempt to create individual from invalid enum.");
            return nullptr;
        }
        return nullptr;
    }

    std::shared_ptr<BaseProfession> getRandomProfession()
    {
        ProfessionType profession = static_cast<ProfessionType>(rand()%NUM_OF_PROFESSIONS);
        return createProfessionFromType(profession);
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

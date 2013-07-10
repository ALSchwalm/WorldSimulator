#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include "Item/BaseItem.h"
#include <vector>
#include <memory>
#include <cstdlib>

namespace Location
{
    class BaseLocation;
    typedef std::shared_ptr<BaseLocation> Location_ptr;
}


namespace Profession
{
    enum ProfessionType
    {
        BAKER,

        //insert before this
        NUM_OF_PROFESSIONS,
        PROFESSION_ERROR
    };

    class BaseProfession;
    typedef std::shared_ptr<BaseProfession> Profession_ptr;

    std::shared_ptr<BaseProfession> createProfessionFromType(ProfessionType _type);
    extern const unsigned int ProfessionValues[];

    //std::vector<Item::Item_ptr> getInitialItems(std::shared_ptr<Individual> individual);


}

#endif

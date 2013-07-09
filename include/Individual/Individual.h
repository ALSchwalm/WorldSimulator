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


namespace Individual
{
    class Individual;


    extern const unsigned int IndividualValues[];

    std::vector<Item::Item_ptr> getInitialItems(std::shared_ptr<Individual> individual);


}

#endif

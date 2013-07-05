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
    class BaseIndividual;

    enum IndividualType
    {
        BAKER,

        //insert before this
        NUM_OF_INDIVIDUALS,
        INDIVIDUAL_ERROR
    };

    extern const unsigned int IndividualValues[];

    std::shared_ptr<BaseIndividual> getRandomIndividual(std::string _name,
                                                        Location::Location_ptr _location,
                                                        bool _isMale=true);

    std::vector<Item::Item_ptr> getInitialItems(std::shared_ptr<BaseIndividual> individual);


}

#endif

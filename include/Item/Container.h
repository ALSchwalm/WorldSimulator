#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item/BaseItem.h"
#include "Location/BaseLocation.h"

namespace Item
{
    class Container : public BaseItem, public Location::BaseLocation
    {
    public:
        const ItemType getItemType() override {return CONTAINER;}
        static constexpr ItemType getStaticItemType(){return CONTAINER;}

        Location::LocationType getLocationType() override {return Location::CONTAINER;}
        static constexpr Location::LocationType getStaticLocationType() {return Location::CONTAINER;}

        Container(ID _id) :
            BaseItem(_id),
            Location::BaseLocation(""){}

    };

}

#endif

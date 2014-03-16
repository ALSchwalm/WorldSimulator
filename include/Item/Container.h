#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item/BaseItem.h"
#include "Location/BaseLocation.h"

namespace Item
{
    class BaseContainer : public BaseItem, public Location::BaseLocation
    {
    public:
        ItemType getItemType() const override {return ItemType::CONTAINER;}

    };

    class BaseContainerPy : public BaseItemPy
    {

    };

}

#endif

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item/BaseItem.h"
#include "Location/BaseLocation.h"

namespace Item
{
    using namespace Location;
    
    class BaseContainer : public virtual BaseItem, public Location::BaseLocation
    {
    public:
        ItemType getItemType() const override {return ItemType::CONTAINER;}
        LocationType getLocationType() const override {return LocationType::CONTAINER;}

        virtual ~BaseContainer(){}

    protected:
        BaseContainer(std::string _name) : Location::BaseLocation(_name) {}

    };

    class BaseContainerPy : public BaseItemPy, public BaseContainer
    {
    public:
        BaseContainerPy(PyObject *p, std::string _name) : BaseItem(_name),
                                                          BaseItemPy(p),
                                                          BaseContainer(_name) {}

    };

}

#endif

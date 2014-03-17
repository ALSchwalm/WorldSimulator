#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item/BaseItem.h"
#include "Location/BaseLocation.h"

namespace Item
{
    class BaseContainer : public virtual BaseItem, public Location::BaseLocation
    {
    public:
        ItemType getItemType() const override {return ItemType::CONTAINER;}

        virtual ~BaseContainer(){}

    protected:
        BaseContainer(){}

    };

    class BaseContainerPy : public BaseItemPy, public BaseContainer
    {
    public:
        BaseContainerPy(PyObject *p) : BaseItemPy(p) {}
    };

}

#endif

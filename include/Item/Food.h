#ifndef FOOD_H_
#define FOOD_H_

#include "Item/BaseItem.h"

namespace Item
{
    class BaseFood : public virtual BaseItem
    {
    public:
        ItemType getItemType() const override {return ItemType::FOOD;}

        virtual ~BaseFood(){}

    private:

    };

    class BaseFoodPy : public BaseItemPy, public BaseFood
    {
    public:
        BaseFoodPy(PyObject *p, std::string _name) : BaseItem(_name),
                                                     BaseItemPy(p) {}
    };
}

#endif

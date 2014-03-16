#ifndef FOOD_H_
#define FOOD_H_

#include "Item/BaseItem.h"

namespace Item
{
    class BaseFood : public BaseItem
    {
    public:
        ItemType getItemType() const override {return ItemType::FOOD;}

    private:

    };

    class BaseFoodPy : public BaseItemPy
    {

    };
}

#endif

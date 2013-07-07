#ifndef ITEMUTILS_H_
#define ITEMUTILS_H_

#include "Item/Food.h"
#include "Item/BaseItem.h"
#include "Item/Tool.h"
#include "Item/Weapon.h"
#include "Item/Container.h"
#include <stdexcept>

namespace Item
{
    /*
    * This template function is used to determine whether an item
    * has a particular "subItemType". That is, given a shared_ptr<BaseItem>
    * which points to a Food instance, whether that Food instance was created
    * with BREAD FoodType.
    */
    template<ItemType itemType>
    inline bool isEnumType(Item_ptr i, unsigned int t);

    template<>
    inline bool isEnumType<FOOD>(Item_ptr i, unsigned int t)
    {
        BaseFood* f = dynamic_cast<BaseFood*>(i.get());
        if (!f || f->getFoodType() != t)
            return false;
        return true;
    }

    template<>
    inline bool isEnumType<CONTAINER>(Item_ptr i, unsigned int t)
    {
        BaseContainer* c = dynamic_cast<BaseContainer*>(i.get());
        if (!c || c->getContainerType() != t)
            return false;
        return true;
    }

    template<>
    inline bool isEnumType<TOOL>(Item_ptr i, unsigned int t)
    {
        BaseTool* tool = dynamic_cast<BaseTool*>(i.get());
        if (!tool || tool->getToolType() != t)
            return false;
        return true;
    }

    template<>
    inline bool isEnumType<WEAPON>(Item_ptr i, unsigned int t)
    {
        BaseWeapon* w = dynamic_cast<BaseWeapon*>(i.get());
        if (!w || w->getWeaponType() != t)
            return false;
        return true;
    }

    inline bool isClassType(Item_ptr i, ItemType itemType, unsigned int t)
    {
        //No default to cause compiler warnings if there is an unhandled case
        switch (itemType)
        {
        case FOOD:
            return isEnumType<FOOD>(i, t);
        case CONTAINER:
            return isEnumType<CONTAINER>(i, t);
        case TOOL:
            return isEnumType<TOOL>(i, t);
        case WEAPON:
            return isEnumType<WEAPON>(i, t);
        case ITEM_ERROR:
            throw(std::runtime_error("Attempt to call isClassType on ITEM_ERROR"));
            return false;
        }

        return false;
    }


}

#endif

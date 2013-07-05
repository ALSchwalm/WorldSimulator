#ifndef ITEMUTILS_H_
#define ITEMUTILS_H_

#include "Item/Food.h"
#include "Item/BaseItem.h"
#include "Item/Tool.h"
#include "Item/Weapon.h"
#include "Item/Container.h"

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
        Food* f = dynamic_cast<Food*>(i.get());
        if (!f || f->getFoodType() != t)
            return false;
        return true;
    }

    template<>
    inline bool isEnumType<CONTAINER>(Item_ptr i, unsigned int t)
    {
        Container* c = dynamic_cast<Container*>(i.get());
        if (!c || c->getContainerType() != t)
            return false;
        return true;
    }

    template<>
    inline bool isEnumType<TOOL>(Item_ptr i, unsigned int t)
    {
        Tool* tool = dynamic_cast<Tool*>(i.get());
        if (!tool || tool->getToolType() != t)
            return false;
        return true;
    }

    template<>
    inline bool isEnumType<WEAPON>(Item_ptr i, unsigned int t)
    {
        Weapon* w = dynamic_cast<Weapon*>(i.get());
        if (!w || w->getWeaponType() != t)
            return false;
        return true;
    }



    template<typename T>
    inline bool isClassType(Item_ptr i, unsigned int t);

    template<>
    inline bool isClassType<Food>(Item_ptr i, unsigned int t)
    {
        return isEnumType<FOOD>(i, t);
    }

    template<>
    inline bool isClassType<Container>(Item_ptr i, unsigned int t)
    {
        return isEnumType<CONTAINER>(i, t);
    }

    template<>
    inline bool isClassType<Tool>(Item_ptr i, unsigned int t)
    {
        return isEnumType<TOOL>(i, t);
    }

    template<>
    inline bool isClassType<Weapon>(Item_ptr i, unsigned int t)
    {
        return isEnumType<WEAPON>(i, t);
    }

}

#endif

#ifndef WEAPON_H_
#define WEAPON_H_

#include "Item/BaseItem.h"

namespace Item
{
    class BaseWeapon : public BaseItem
    {
    public:
        ItemType getItemType() const override {return ItemType::WEAPON;}

    private:
    };

    class BaseWeaponPy : public BaseItemPy
    {

    };
}

#endif

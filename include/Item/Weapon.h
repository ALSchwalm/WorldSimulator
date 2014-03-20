#ifndef WEAPON_H_
#define WEAPON_H_

#include "Item/BaseItem.h"

namespace Item
{
    class BaseWeapon : public virtual BaseItem
    {
    public:
        ItemType getItemType() const override {return ItemType::WEAPON;}

        virtual ~BaseWeapon(){}

    private:

    };

    class BaseWeaponPy : public BaseItemPy, public BaseWeapon
    {
    public:
        BaseWeaponPy(PyObject *p, std::string _name) : BaseItem(_name),
                                                       BaseItemPy(p) {}
    };
}

#endif

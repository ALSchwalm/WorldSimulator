#ifndef WEAPON_H_
#define WEAPON_H_

#include "Item/BaseItem.h"

namespace Item
{
    enum class DamageType
    {
        PIERCING,
        SLASHING,
        BLUNT
    };

    class BaseWeapon : public virtual BaseItem
    {
    public:
        ItemType getItemType() const override {return ItemType::WEAPON;}

        dict getDamageModifiers() {return damageModifiers;}
        void setDamageModifiers(dict modifiers) {damageModifiers = modifiers;}

        virtual ~BaseWeapon(){}

    private:
        dict damageModifiers;
    };

    class BaseWeaponPy : public BaseItemPy, public BaseWeapon
    {
    public:
        BaseWeaponPy(PyObject *p, std::string _name) : BaseItem(_name),
                                                       BaseItemPy(p) {}
    };
}

#endif

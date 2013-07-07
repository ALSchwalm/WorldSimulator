#ifndef WEAPON_H_
#define WEAPON_H_

#include "Item/BaseItem.h"
#include "Skill/Skill.h"
#include <memory>
#include <map>
#include <string>
#include <vector>

namespace Item
{
    enum WeaponType
    {
        SWORD,
        BOW,

        NUM_OF_WEAPONS
    };

    const std::string weaponTypeAsString[NUM_OF_WEAPONS] = {
        "Sword",
        "Bow"
    };

    const std::map<WeaponType, const Skill::skillMap> requiredWeaponSkills
    {
        {SWORD, 	{{Skill::BLACKSMITHING, 	2.5f},
                    {Skill::WOODWORKING,		0.5f}}},

        {BOW,		{{Skill::WOODWORKING, 		3.0f}}}
    };

    const std::map<WeaponType, const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>> requiredWeaponItems
    {
        {SWORD,		{std::make_tuple(WEAPON, SWORD, 1)}}
    };


    class BaseWeapon : public BaseItem
    {
    public:
        const ItemType getItemType() override {return TOOL;}
        const WeaponType getWeaponType() {return weaponType;}

    protected:
        BaseWeapon(std::string _name, Individual::Individual_ptr _owner, WeaponType _w) :
            BaseItem(_name, _owner),
            weaponType(_w){}
    private:
        WeaponType weaponType;
    };


    template<WeaponType w>
    class Weapon : public BaseWeapon
    {
    public:
        typedef WeaponType type;
        typedef BaseWeapon baseType;

        Weapon() : Weapon(weaponTypeAsString[w], nullptr){}

        Weapon(std::string _name) : Weapon(_name, nullptr){}

        Weapon(Individual::Individual_ptr _owner) :
            Weapon(weaponTypeAsString[w], _owner){}

        Weapon(std::string _name, Individual::Individual_ptr _owner ) :
            BaseWeapon(_name, _owner, w){}

        ~Weapon(){};

        static const Skill::skillMap& getRequiredSkill(){return requiredWeaponSkills.at(w);}
        static const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>& getRequiredItems()
        {
            return requiredWeaponItems.at(w);
        }

        const ItemType getItemType() override {return WEAPON;}
        static constexpr ItemType getStaticItemType(){return WEAPON;}
    };

}

#endif

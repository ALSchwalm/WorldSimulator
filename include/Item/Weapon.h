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
    class Weapon : public BaseItem
    {
    public:
        const ItemType getItemType() override {return TOOL;}

        Weapon(ID _id, std::string _name, std::map<std::string, bool> _attributes) :
        	BaseItem(_id, _name, _attributes){}

        Weapon(ID _id, std::string _name, Individual::Individual_ptr _owner) :
            BaseItem(_id, _name, _owner){}

        Weapon(ID _id, Individual::Individual_ptr _owner) :
            BaseItem(_id, "Unnamed Weapon", _owner){}

        Weapon(ID _id) :
        	BaseItem(_id, "Unnamed Weapon"){}

    private:
    };
}

#endif

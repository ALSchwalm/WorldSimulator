#ifndef FOOD_H_
#define FOOD_H_

#include <memory>
#include <map>
#include <string>
#include <vector>
#include "Item/BaseItem.h"
#include "Skill/Skill.h"

namespace Item
{
    class Food : public BaseItem
    {
    public:
        const ItemType getItemType() override {return FOOD;}
        Food(ID _id) :
            BaseItem(_id, "Unnamed Food"){}

        Food(ID _id, std::string _name, std::map<std::string, bool> _attributes) :
        	BaseItem(_id, _name, _attributes){}

    private:

    };
}

#endif

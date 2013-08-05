#ifndef TOOL_H_
#define TOOL_H_

#include <memory>
#include <map>
#include <string>
#include <vector>
#include "Item/BaseItem.h"
#include "Skill/Skill.h"

namespace Item
{

    class Tool : public BaseItem
    {
    public:
        const ItemType getItemType() override {return TOOL;}

        Tool(ID _id, std::string _name, std::map<std::string, bool> _attributes) :
        	BaseItem(_id, _name, _attributes){}

        Tool(ID _id, std::string _name) :
            BaseItem(_id, _name)
        {}

        Tool(ID _id) :
            BaseItem(_id, "Unnamed Tool")
        {}

    private:

    };
}

#endif

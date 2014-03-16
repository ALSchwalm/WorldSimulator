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

    class BaseTool : public BaseItem
    {
    public:
        ItemType getItemType() const override {return ItemType::TOOL;}


    private:

    };

    class BaseToolPy : public BaseItemPy
    {

    };
}

#endif

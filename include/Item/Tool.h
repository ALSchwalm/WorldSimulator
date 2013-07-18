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

    enum ToolType
    {
        PLOW,
        OVEN,

        NUM_OF_TOOLS
    };

    const std::string toolTypeAsString[] = {
        "Plow",
        "Oven",
    };

    static_assert(sizeof(toolTypeAsString)/sizeof(toolTypeAsString[0]) == NUM_OF_TOOLS,
            "ToolType not given string.");

    /*
    * The skill level required to create this tool
    * (using other tools etc)
    */
    const std::map<ToolType, const Skill::skillMap> requiredToolSkills
    {
        {PLOW, 	{{Skill::BLACKSMITHING, 	1.5f},
                {Skill::WOODWORKING,		0.5f}}},

        {OVEN,	{{Skill::BLACKSMITHING, 	3.0f}}}
    };

    /*
    * A tools 'skill' is a multiplier when calculating how
    * effective it is to use. Using map because we don't have
    * designated initializers for some reason
    */
    const std::map<ToolType, const Skill::skillMap> usedToolSkills
    {
        {PLOW,	{{Skill::FARMING, 	1.5f}}},

        {OVEN,	{{Skill::COOKING, 	3.0f},
                {Skill::BAKING,  	3.0f}}}
    };

    const std::map<ToolType, const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>> requiredToolItems
    {
        {PLOW,		{std::make_tuple(TOOL, PLOW, 1)}}
    };


    class BaseTool : public BaseItem
    {
    public:
        const ItemType getItemType() override {return TOOL;}
        const ToolType getToolType() {return toolType;}

    protected:
        BaseTool(std::string _name, ToolType _t) :
            BaseItem(_name),
            toolType(_t)
        {}
    private:
        ToolType toolType;
    };


    template<ToolType t>
    class Tool : public BaseTool
    {
    public:
        typedef ToolType type;
        typedef BaseTool baseType;

        static Item_ptr getRandomTool();
        static const Skill::skillMap& getRequiredSkill(){return requiredToolSkills.at(t);}
        static const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>& getRequiredItems()
        {
            return requiredToolItems.at(t);
        }

        Tool();
        ~Tool(){};

        const ItemType getItemType() override {return TOOL;}
        static constexpr ItemType getStaticItemType(){return TOOL;}
    };

}

#endif

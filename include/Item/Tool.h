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

	const std::string toolTypeAsString[NUM_OF_TOOLS] = {
		"Plow",
		"Oven",
	};

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

	class Tool : public BaseItem
	{
	public:
		static Item_ptr getRandomTool();
		static const Skill::skillMap & getRequiredSkill(ToolType t){return requiredToolSkills.at(t);}

		Tool(ToolType _toolType);
		~Tool(){};

	private:
		ToolType toolType;

	};

}

#endif

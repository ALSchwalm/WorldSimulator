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

	};

	/*
	 * The skill level required to create this tool
	 * (using other tools etc)
	 */
	const Skill::skillMap requiredContainerSkills[NUM_OF_TOOLS]
	{
		{//PLOW
			{Skill::BLACKSMITHING, 	2.5f},
			{Skill::WOODWORKING,	1.0f}
		},

		{//OVEN
			{Skill::BLACKSMITHING, 	3.0f},
		}
	};

	/*
	 * A tools 'skill' is a multiplier when calculating how
	 * effective it is to use.
	 */
	const Skill::skillMap usedContainerSkills[NUM_OF_TOOLS]
	{
		{//PLOW
			{Skill::FARMING, 	1.5f}
		},

		{//OVEN
			{Skill::COOKING, 	3.0f},
			{Skill::BAKING,  	3.0f}
		}
	};


	class Tool : public BaseItem
	{
	public:
		static Item_ptr getRandomTool();

		Tool(ToolType _toolType);
		~Tool(){};

	private:
		ToolType toolType;

	};

}

#endif

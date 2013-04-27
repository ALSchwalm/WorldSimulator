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

	class Tool : public BaseItem
	{
	public:
		static Item_ptr getRandomTool();

		Tool(ToolType _toolType);
		~Tool(){};

	private:
		ToolType toolType;

		/*
		 * A tools 'skill' is a multiplier when calculating how
		 * effective it is to use.
		 */
		Skill::skillMap skillMap;
	};

}

#endif

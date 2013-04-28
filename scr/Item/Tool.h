
#include "Item/Tool.h"
#include <cstdlib>

namespace Item
{

	Item_ptr Tool::getRandomTool()
	{

		return std::make_shared<Tool>( (ToolType) (rand() % ToolType::NUM_OF_TOOLS));
	};

	Tool::Tool(ToolType _toolType) :
		BaseItem(toolTypeAsString[_toolType]),
		toolType(_toolType)
	{
	}

}

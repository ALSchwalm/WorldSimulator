
#include "Item/Tool.h"
#include <cstdlib>

namespace Item
{

    template<ToolType t>
    Item_ptr Tool<t>::getRandomTool()
    {
        //return std::make_shared<Tool>( (ToolType) (rand() % ToolType::NUM_OF_TOOLS));
    };

    template<ToolType t>
    Tool<t>::Tool() :
        BaseItem(toolTypeAsString[t], t)
    {
    }

}


#include "Item/BaseItem.h"

namespace Item
{
	bool BaseItem::hasAttribute(const std::string& s)
	{
		auto location = attributes.find(s);
		if (location != attributes.end())
		{
			return location->second;
		}
		return false;
	}
}

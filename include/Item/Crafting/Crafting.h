#ifndef CRAFTING_H_
#define CRAFTING_H_

#include "Item/BaseItem.h"
#include "Individual/BaseIndividual.h"
#include <memory>

namespace Item
{
	namespace Crafting
	{
		template<typename T, typename EnumType>
		inline Item_ptr createItem(EnumType enumType, Individual::Individual_ptr individual)
		{
			for (auto p : T::getRequiredSkill(enumType))
			{
				if (individual->getSkillMap()[p.first] < p.second)
					return nullptr;
			}
			return std::make_shared<T>(enumType);
		}
	}
}

#endif

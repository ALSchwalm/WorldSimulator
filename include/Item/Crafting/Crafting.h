#ifndef CRAFTING_H_
#define CRAFTING_H_

#include "Item/BaseItem.h"
#include "Individual/BaseIndividual.h"
#include <memory>
#include <type_traits>

namespace Item
{
	namespace Crafting
	{

		template<typename T, typename EnumType>
		static bool hasItems(EnumType enumType, Individual::Individual_ptr individual)
		{
			auto requiredItems = T::getRequiredItems(enumType);
			for (auto p : requiredItems)
			{

			}
			return true;
		}

		template<typename T, typename EnumType>
		inline Item_ptr createItem(EnumType enumType, Individual::Individual_ptr individual)
		{

			static_assert(std::is_enum<EnumType>::value, "Template argument is not an enum.");

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

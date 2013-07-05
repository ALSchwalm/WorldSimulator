#ifndef CRAFTING_H_
#define CRAFTING_H_

#include "Item/BaseItem.h"
#include "Individual/BaseIndividual.h"
#include "Item/ItemUtils.h"
#include <memory>
#include <type_traits>

namespace Item
{
    namespace Crafting
    {

        template<typename T, typename EnumType>
        static const std::vector<Item_ptr> hasItems(EnumType enumType, Individual::Individual_ptr individual)
        {
            std::vector<Item_ptr> usedItems;
            auto requiredItems = T::getRequiredItems(enumType);
            for (auto p : requiredItems)
            {
                auto items = individual->getItems();
                auto found_item = std::find_if(items.begin(), items.end(),
                        [=](Item_ptr i) {return isClassType<T>(i, std::get<1>(p));});

                if (found_item == items.end())
                {
                    usedItems.clear();
                    break;
                }
                else
                {
                    usedItems.push_back(*found_item);
                }
            }
            return usedItems;
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
            if (hasItems<T>(enumType, individual).size() == 0)
                return nullptr;

            return std::make_shared<T>(enumType);
        }
    }
}

#endif

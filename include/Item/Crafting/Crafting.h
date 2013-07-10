#ifndef CRAFTING_H_
#define CRAFTING_H_

#include "Item/BaseItem.h"
#include "Individual/Individual.h"
#include "Item/ItemUtils.h"
#include <memory>
#include <type_traits>

namespace Item
{
    namespace Crafting
    {

        template<typename T>
        static const std::vector<Item_ptr> hasItems(Individual::Individual_ptr individual)
        {
            std::vector<Item_ptr> usedItems;
            auto requiredItems = T::getRequiredItems();
            for (auto p : requiredItems)
            {
                auto items = individual->getItems();
                auto found_item = std::find_if(items.begin(), items.end(),
                        [&](Item_ptr i) {return isClassType(i, std::get<0>(p), std::get<1>(p));});

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

        template<typename T>
        inline Item_ptr createItem(Individual::Individual_ptr individual)
        {
            for (auto p : T::getRequiredSkill())
            {
                if (individual->getSkillLevel(p.first) < p.second)
                    return nullptr;
            }
            if (hasItems<T>(individual).size() == 0)
                return nullptr;

            return std::make_shared<T>();
        }
    }
}

#endif

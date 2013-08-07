#ifndef CRAFTING_H_
#define CRAFTING_H_

#include "Item/BaseItem.h"
#include "Actor/Individual.h"
#include "Item/ItemUtils.h"
#include "Item/ItemFactory.h"
#include <memory>
#include <type_traits>

namespace Item
{
    namespace Crafting
    {
        template<typename... T>
        inline Item_ptr createItem(ID id, Individual::Individual_ptr individual, T... args)
        {
        	auto factory = getItemFactoryFromID(id);
        	if (factory == itemFactories.end())
        		return nullptr;

        	auto&& itemFactory = *factory;

        	std::vector<Item_ptr> usedItems;
        	for(auto item : itemFactory->getRequiredItems())
        	{
        		auto items = individual->getItems();
        		auto location = std::find_if(items.begin(), items.end(),
        				[&](Item_ptr i) {
        					return (i->getID() == id &&
        							std::find(usedItems.begin(), usedItems.end(), i) != usedItems.end());
        				});
        		if(location != items.end()) {
        			usedItems.push_back(*location);
        		}
        		else
        		{
        			return nullptr;
        		}
        	}

			for (auto item : usedItems)
				individual->removeItem(item);

            return itemFactory->make(args...);
        }
    }
}

#endif

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
        inline Item_ptr createItem(ID id, Actor::Individual_ptr individual, T... args)
        {
            auto factory = getItemFactoryFromID(id);
            if (factory == itemFactories.end())
                return nullptr;

            auto&& itemFactory = *factory;

            //TODO: remove appropriate items
            return itemFactory->make(args...);
        }
    }
}

#endif

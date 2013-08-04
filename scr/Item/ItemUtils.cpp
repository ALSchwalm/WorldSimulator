
#include "Item/ItemUtils.h"
#include "Item/ItemFactory.h"

namespace Item
{

    bool AddItemFactory(const Json::Value itemRoot) {

    	auto type = itemRoot["Type"].asString();
    	if (type == "Food") {
    		std::unique_ptr<ItemFactoryBase> newFactory(new ItemFactory<FOOD>(itemRoot));
    		itemFactories.push_back(std::move(newFactory));
    	}
    	else if (type == "Tool") {
    		std::unique_ptr<ItemFactoryBase> newFactory(new ItemFactory<TOOL>(itemRoot));
    		itemFactories.push_back(std::move(newFactory));
    	}
    	else if (type == "Weapon") {
    		std::unique_ptr<ItemFactoryBase> newFactory(new ItemFactory<WEAPON>(itemRoot));
    		itemFactories.push_back(std::move(newFactory));
    	}
    	else if (type == "Container") {
    		std::unique_ptr<ItemFactoryBase> newFactory(new ItemFactory<CONTAINER>(itemRoot));
    		itemFactories.push_back(std::move(newFactory));
    	}
    	else {
    		return false;
    	}
        return true;
    }

}

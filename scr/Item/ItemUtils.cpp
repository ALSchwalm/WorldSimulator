
#include "Item/ItemUtils.h"
#include "Item/ItemFactory.h"

namespace Item
{

    bool AddItemFactory(const Json::Value itemRoot) {

    	auto type = itemRoot["Type"].asString();
    	ItemFactoryBase* newFactory = nullptr;
    	if (type == "Food") {
    		newFactory = new ItemFactory<FOOD>(itemRoot);
    	}
    	else if (type == "Tool") {
    		newFactory = new ItemFactory<TOOL>(itemRoot);
    	}
    	else if (type == "Weapon") {
    		newFactory = new ItemFactory<WEAPON>(itemRoot);
    	}
    	else if (type == "Container") {
    		newFactory = new ItemFactory<CONTAINER>(itemRoot);
    	}
    	else {
    		return false;
    	}

    	std::unique_ptr<ItemFactoryBase> factPtr(newFactory);
    	itemFactories.push_back(std::move(factPtr));
        return true;
    }

}

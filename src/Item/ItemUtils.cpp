
#include "Item/ItemUtils.h"
#include "Item/ItemFactory.h"
#include <boost/python.hpp>

namespace Item
{

    bool AddItemFactory(boost::python::object obj) {

    	ItemFactoryBase* newFactory = new ItemFactory(obj)
    	std::unique_ptr<ItemFactory> factPtr(newFactory);
    	itemFactories.push_back(std::move(factPtr));
        return true;
    }

    std::vector<std::unique_ptr<Item::ItemFactoryBase>>::iterator
    	getItemFactoryFromAttribute(const std::string& attribute, bool value)
    {
    	auto factory=itemFactories.begin();
    	for (; factory != itemFactories.end(); ++factory) {
    		if ( (*factory)->hasAttribute(attribute) ) {
    			return factory;
    		}
    	}
    	return factory;
    }

    std::vector<std::unique_ptr<Item::ItemFactoryBase>>::iterator
    	getItemFactoryFromID(ID _id)
    {
    	auto factory=itemFactories.begin();
    	for (; factory != itemFactories.end(); ++factory) {
    		if ( (*factory)->getID() == _id ) {
    			return factory;
    		}
    	}
    	return factory;
    }


}

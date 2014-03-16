
#include "Item/ItemUtils.h"
#include <boost/python.hpp>

namespace Item
{

    bool AddItemFactory(boost::python::object obj) {

    	ItemFactory* newFactory = new ItemFactory(obj);
    	std::unique_ptr<ItemFactory> factPtr(newFactory);
    	itemFactories.push_back(std::move(factPtr));
        return true;
    }

    std::vector<std::unique_ptr<Item::ItemFactory>>::iterator
    getItemFactoryFromID(ID _id)
    {
    	auto factory=itemFactories.begin();
    	for (; factory != itemFactories.end(); ++factory) {
    		if ( (*factory)->getClassID() == _id ) {
    			return factory;
    		}
    	}
    	return factory;
    }


}

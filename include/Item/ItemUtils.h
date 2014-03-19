#ifndef ITEMUTILS_H_
#define ITEMUTILS_H_

#include "Item/ItemFactory.h"
#include <boost/python.hpp>
#include <utility>
#include <vector>
#include <memory>

namespace Item
{
    class ItemFactory;

    using ID = unsigned long;
    using skillVector = std::vector< std::pair<ID, double>>;
    using itemVector = std::vector< std::pair<ID, unsigned int>>;

    bool AddItemFactory(boost::python::object);

    template<typename T>
    std::vector<std::unique_ptr<Item::ItemFactory>>::iterator
    getItemFactoryFromAttribute(const std::string& attribute, const T& val)
    {
    	auto factory=itemFactories.begin();
    	for (; factory != itemFactories.end(); ++factory) {
            if ( (*factory)->hasAttribute(attribute) ) {
                return factory;
            }
    	}
    	return factory;
    }

    std::vector<std::unique_ptr<Item::ItemFactory>>::iterator
    getItemFactoryFromID(ID _id);
}

#endif

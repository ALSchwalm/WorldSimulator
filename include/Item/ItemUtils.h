#ifndef ITEMUTILS_H_
#define ITEMUTILS_H_

#include <boost/python.hpp>
#include <utility>
#include <vector>
#include <memory>

namespace Item
{
	class ItemFactoryBase;

	typedef const std::string ID;
	typedef std::vector< std::pair<ID, double>> skillVector;
	typedef std::vector< std::pair<ID, unsigned int>> itemVector;

    bool AddItemFactory(boost::python::object);

    std::vector<std::unique_ptr<Item::ItemFactoryBase>>::iterator
    	getItemFactoryFromAttribute(const std::string& attribute, bool value=true);

    std::vector<std::unique_ptr<Item::ItemFactoryBase>>::iterator
    	getItemFactoryFromID(ID _id);
}

#endif

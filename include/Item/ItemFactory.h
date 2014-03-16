#ifndef ITEMFACTORY_H_
#define ITEMFACTORY_H_

#include "Item/BaseItem.h"
#include <boost/python.hpp>
#include <vector>

namespace Item
{

    class ItemFactory
    {
    public:
        template<typename... Args>
        std::shared_ptr<BaseItem> make(Args args) const {
            return extract<std::shared_ptr<BaseItem>>(pyClass(args...));
        }

        ItemFactoryBase(object _pyClass) : pyclass(_pyClass) {}

        bool hasAttribute(const std::string& s) const {
            return pyClass.attr("default_attributes").has_key(s);
        }

    private:
        object pyClass;
    };

    extern std::vector<std::unique_ptr<ItemFactory>> itemFactories;
}

#endif

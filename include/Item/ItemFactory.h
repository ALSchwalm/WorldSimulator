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
        std::shared_ptr<BaseItem> make(Args... args) const {
            return extract<std::shared_ptr<BaseItem>>(pyClass(args...));
        }

        ItemFactory(object _pyClass) : pyClass(_pyClass) {}

        bool hasAttribute(const std::string& s) const {
            dict default_attributes = extract<dict>(pyClass.attr("default_attributes"));
            return default_attributes.has_key(s);
        }

        ID getClassID() const {
            return extract<ID>(pyClass.attr("classID"));
        }

        list getRequiredItems() const {
            return call_method<list>(pyClass.ptr(), "getRequiredItems");
        }

    private:
        object pyClass;
    };

    extern std::vector<std::unique_ptr<ItemFactory>> itemFactories;
}

#endif

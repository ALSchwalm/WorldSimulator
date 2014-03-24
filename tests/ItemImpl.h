#ifndef ITEMIMPL_H_
#define ITEMIMPL_H_

#include <boost/python.hpp>
#include "Item/Container.h"

namespace Test
{
    using namespace Item;

    template<typename T>
    class ItemImpl : public T
    {
    public:
        ItemImpl(std::string _name) : BaseItem(_name){}

        ID getClassID() const override {
            return 1;
        }

    };

    template<>
    class ItemImpl<BaseContainer> : public BaseContainer
    {
    public:
        ItemImpl(std::string _name) : BaseItem(_name),
                                      BaseContainer(_name){}

        ID getClassID() const override {
            return 1;
        }
    };
}

#endif

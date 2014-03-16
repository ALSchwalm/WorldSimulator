#ifndef BASEITEM_H_
#define BASEITEM_H_

#include "Owner/Owner.h"
#include <boost/python.hpp>
#include <string>
#include <memory>

namespace Item
{
    using namespace boost::python;
    using ID = unsigned long;

    class BaseItem
    {
    public:
        const std::string& getName() {return name;}
        virtual ID getClassID() const=0;

        dict getAttributes() {return attributes;}
        void setAttributes(dict attr) { attributes = attr;}

        template<typename T>
        void setAttribute(std::string name, T val) { attributes[name] = val;}
        bool hasAttribute(std::string name) const { return attributes.has_key(name); }

        template<typename T>
        const T& getAttribute(std::string name) const { return extract<T&>(attributes[name]); }

        const Owner::Owner& getOwner() const {return owner;}
        void setOwner(const Owner::Owner _owner) {owner=_owner;}

        BaseItem(const BaseItem&) = delete;
        BaseItem& operator=(const BaseItem&) = delete;
        virtual ~BaseItem(){};

    protected:
        BaseItem(){}

        std::string name;
        Owner::Owner owner;
        dict attributes;
    };

    using Item_ptr = std::shared_ptr<BaseItem>;
    using ItemList = std::vector<Item_ptr>;

    class BaseItemPy : public BaseItem
    {
    public:
        BaseItemPy(PyObject *p) : self(p) {}

        ID getClassID() const override {
            return call_method<ID>(self, "getClassID");
        }

    private:
        PyObject *self;

    };
}

#endif

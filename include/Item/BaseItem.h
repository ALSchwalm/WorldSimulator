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

    enum class ItemType {
        TOOL,
        WEAPON,
        FOOD,
        CONTAINER,

        ERROR
    };

    class BaseItem
    {
    public:
        const std::string& getName() {return name;}
        virtual ID getClassID() const=0;

        virtual ItemType getItemType() const { return ItemType::ERROR; }

        dict getAttributes() {return attributes;}
        void setAttributes(dict attr) { attributes = attr;}

        template<typename T>
        void setAttribute(const std::string& name, T val) { attributes[name] = val;}

        bool hasAttribute(const std::string& name) const {
            return attributes.has_key(name);
        }

        template<typename T>
        const T& getAttribute(const std::string& name) const {
            return extract<T&>(attributes[name]);
        }

        const Owner::Owner& getOwner() const {return owner;}
        void setOwner(const Owner::Owner _owner) {owner=_owner;}

        virtual list getRequiredItems() const=0;

        BaseItem(const BaseItem&) = delete;
        BaseItem& operator=(const BaseItem&) = delete;
        virtual ~BaseItem(){};

    protected:
        BaseItem(std::string _name) : name(_name) {}
        BaseItem() : BaseItem("Unnamed Item") {}

        std::string name;
        Owner::Owner owner;
        dict attributes;
    };

    using Item_ptr = std::shared_ptr<BaseItem>;
    using ItemList = std::vector<Item_ptr>;

    class BaseItemPy : public virtual BaseItem
    {
    public:
        BaseItemPy(PyObject *p) : self(p) {}
        BaseItemPy(PyObject *p, std::string _name) : BaseItem(_name), self(p) {}

        ID getClassID() const override {
            return call_method<ID>(self, "getClassID");
        }

        list getRequiredItems() const override {
            return call_method<list>(self, "getRequiredItems");
        }

    protected:
        PyObject *self;

    };
}

#endif

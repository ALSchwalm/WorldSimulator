#ifndef BASEITEM_H_
#define BASEITEM_H_

#include "Owner/Owner.h"
#include "Skill/Skill.h"
#include <memory>
#include <map>
#include <string>
#include <vector>

namespace Individual
{
    class Individual;
    typedef std::shared_ptr<Actor::Individual> Individual_ptr;
}

namespace Item
{
    enum ItemType
    {
        FOOD,
        WEAPON,
        CONTAINER,
        TOOL,

        ITEM_ERROR
    };


    class BaseItem
    {
    public:

        virtual ~BaseItem(){};

        std::string getName() {return name;}
        void setAttribute(std::string s) {attributes[s] = true;}

        virtual const ItemType getItemType()=0;

        const Owner::Owner & getOwner() {return owner;}
        void setOwner(const Owner::Owner _owner) {owner=_owner;}

        bool hasAttribute(std::string s) {return attributes.find(s) != attributes.end();}

    protected:
        BaseItem(std::string _name, Actor::Individual_ptr _owner) :
            name(_name),
            owner(_owner){}

        BaseItem() : name("Unnamed Item"){}
        BaseItem(std::string _name) : name(_name){}
        BaseItem(Actor::Individual_ptr _owner) :
            name("Unnamed Item"),
            owner(_owner){}



        BaseItem(const BaseItem&) = delete;
        BaseItem& operator=(const BaseItem&) = delete;

    private:
        std::string name;
        std::map<std::string, bool> attributes;
        Owner::Owner owner;

    };

    typedef std::shared_ptr<BaseItem> Item_ptr;
    typedef std::vector<Item_ptr> ItemList;


}

#endif

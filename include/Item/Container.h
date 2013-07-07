#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item/BaseItem.h"
#include "Location/BaseLocation.h"

namespace Item
{

    enum containerType
    {
        BARREL,
        CHEST,
        HOUSE,
        HOUSE_FLOOR,

        NUM_OF_CONTAINERS
    };

    const std::string containerTypeAsString[NUM_OF_CONTAINERS] = {
        "Barrel",
        "Chest",
        "House",
        "House Floor"	//TODO find a way to have numbered floors
    };

    const std::map<containerType, const Skill::skillMap> requiredContainerSkills
    {
        {BARREL, 		{{Skill::WOODWORKING, 	1.5f},
                        {Skill::BLACKSMITHING,	0.5f}}},

        {CHEST, 		{{Skill::WOODWORKING, 	2.0f}}},

        {HOUSE, 		{{Skill::WOODWORKING, 	5.0f}}},

        {HOUSE_FLOOR, 	{{Skill::WOODWORKING, 	3.0f}}}

    };

    const std::map<containerType, const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>> requiredContainerItems
    {
        {BARREL,		{std::make_tuple(CONTAINER, BARREL, 1)}}
    };

    class BaseContainer : public BaseItem
    {
    public:
        const ItemType getItemType() override {return CONTAINER;}
        const containerType getContainerType() {return containertype;}

    protected:
        BaseContainer(std::string _name, containerType _c) :
            BaseItem(_name),
            containertype(_c)
        {}
    private:
        containerType containertype;
    };


    template<containerType c>
    class Container : public BaseContainer, public Location::BaseLocation
    {
    public:
        typedef containerType type;
        typedef BaseContainer baseType;

        Container(std::string _name) :
            BaseContainer(_name, c),
            Location::BaseLocation(_name){}

        Container() : Container(containerTypeAsString[c]){}

        ~Container(){};

        static const Skill::skillMap& getRequiredSkill()
        {
            return requiredContainerSkills.at(c);
        }

        static const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>& getRequiredItems()
        {
            return requiredContainerItems.at(c);
        }

        Location::LocationType getLocationType(){return Location::CONTAINER;}

        const std::vector<Item_ptr>& getItems() {return items;}
        void addItem(Item_ptr _item) {items.push_back(_item);}

        const ItemType getItemType(){return CONTAINER;}
        static constexpr ItemType getStaticItemType(){return CONTAINER;}

    private:
        std::vector<Item_ptr> items;

    };

}

#endif

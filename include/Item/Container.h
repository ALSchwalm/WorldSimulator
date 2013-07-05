#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item/BaseItem.h"
#include "Location/BaseLocation.h"

namespace Item
{

	enum ContainerType
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

	const std::map<ContainerType, const Skill::skillMap> requiredContainerSkills
	{
		{BARREL, 		{{Skill::WOODWORKING, 	1.5f},
						 {Skill::BLACKSMITHING,	0.5f}}},

		{CHEST, 		{{Skill::WOODWORKING, 	2.0f}}},

		{HOUSE, 		{{Skill::WOODWORKING, 	5.0f}}},

		{HOUSE_FLOOR, 	{{Skill::WOODWORKING, 	3.0f}}}

	};

	const std::map<ContainerType, const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>> requiredContainerItems
	{
		{BARREL,		{std::make_tuple(CONTAINER, BARREL, 1)}}
	};


	class Container : public BaseItem, public Location::BaseLocation
	{
	public:
		Container(std::string _name, ContainerType _containerType) :
			BaseItem(_name),
			Location::BaseLocation(_name),
			containerType(_containerType){};

		Container(ContainerType _containerType) :
			BaseItem(containerTypeAsString[_containerType]),
			Location::BaseLocation(containerTypeAsString[_containerType]),
			containerType(_containerType){};

		~Container(){};

		static const Skill::skillMap & getRequiredSkill(ContainerType t){return requiredContainerSkills.at(t);}
		static const std::vector<std::tuple<ItemType, unsigned int, unsigned int>> & getRequiredItems(ContainerType t)
		{
			return requiredContainerItems.at(t);
		}

		Location::LocationType getLocationType(){return Location::CONTAINER;}

		const std::vector<Item_ptr> & getItems() {return items;}
		void addItem(Item_ptr _item) {items.push_back(_item);}

		const ItemType getItemType(){return CONTAINER;}
		const ContainerType getContainerType() {return containerType;}

	private:
		ContainerType containerType;
		std::vector<Item_ptr> items;

	};

}

#endif

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

		Location::LocationType getLocationType(){return Location::CONTAINER;}
		const std::vector<Item_ptr> & getItems() {return items;}
		void addItem(Item_ptr _item) {items.push_back(_item);}

	private:
		ContainerType containerType;
		std::vector<Item_ptr> items;

	};

}

#endif

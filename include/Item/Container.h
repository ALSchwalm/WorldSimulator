#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Item/BaseItem.h"
#include "Location/BaseLocation.h"

namespace Item
{
    class Container : public BaseItem, public Location::BaseLocation
    {
    public:
        const ItemType getItemType() override {return CONTAINER;}
        static constexpr ItemType getStaticItemType(){return CONTAINER;}

        Location::LocationType getLocationType() override {return Location::CONTAINER;}
        static constexpr Location::LocationType getStaticLocationType() {return Location::CONTAINER;}

        virtual void setAttribute(std::string s, bool value=true) override {
        	BaseItem::setAttribute(s, value);
        	Location::BaseLocation::setAttribute(s, value);
        }

        Container(ID _id, std::string _name, std::map<std::string, bool> _attributes) :
        	BaseItem(_id, _name, _attributes),
        	Location::BaseLocation(""){}

        Container(ID _id) :
            BaseItem(_id, "Unnamed Container"),
            Location::BaseLocation(""){}

    };

}

#endif

/*
 * Location.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef BASELOCATION_H_
#define BASELOCATION_H_

#include "Actor/Individual.h"
#include "Event/Event.h"
#include "Item/BaseItem.h"
#include <memory>
#include <unordered_set>
#include <cassert>

namespace Location
{
    typedef std::shared_ptr<BaseLocation> Location_ptr;

    enum LocationType
    {
        VILLAGE,
        REGION,
        WORLD,
        TERRAIN,
        CONTAINER,

        //insert before this
        NUM_OF_LOCATIONS,
        LOCATION_ERROR
    };

    const std::string locationNames[] = {
            "Village",
            "Region",
            "World",
            "Terrain",
            "Container"
    };

    static_assert(sizeof(locationNames)/sizeof(locationNames[0]) == NUM_OF_LOCATIONS,
            "LocationType not given string.");

    inline const std::string& toString(LocationType t) {
        assert(t != NUM_OF_LOCATIONS && t != LOCATION_ERROR);
        return locationNames[t];
    }

    class BaseLocation
    {
    public:
        virtual ~BaseLocation(){};

        virtual std::string getName() {return name;}

        virtual LocationType getLocationType() const=0;

        virtual void setAttribute(std::string s, bool value=true) {attributes[s] = value;}
        bool hasAttribute(const std::string& s) const;

        const Actor::IndividualList& getIndividuals() {return individuals;}
        const Item::ItemList& getItems() {return items;}
        const Event::EventHistory & getHistory(){return history;}
        const std::unordered_set<Location_ptr>& getLocations() {return locations;}
        const std::unordered_set<Location_ptr> getLocationsByAttribute(std::string s);
        const std::unordered_set<Location_ptr> getLocationsByType(LocationType);


        void addEvent(shared_ptr<Event::BaseEvent> e) {history.push_back(e);}
        //Typically, locations are wrapped in shared_ptr so add<Type> is more appropriate
        virtual void addItem(Item::Item_ptr i) { items.push_back(i); }
        bool removeItem(Item::Item_ptr i);

        virtual void addIndividual(Actor::Individual_ptr i){individuals.push_back(i);}

        void addLocation(Location::Location_ptr l);
        void removeLocation(Location::Location_ptr l);

        //FIXME These should only be used by GoalCreator
        Location_ptr cameFrom;
        unsigned int distance;

    protected:
        BaseLocation(std::string _name) : distance(0), name(_name) {}
        BaseLocation(std::string _name, std::map<std::string, bool> _attributes) :
        	name(_name),
        	attributes(_attributes){}

        BaseLocation() : BaseLocation("Unnamed Location"){}

        BaseLocation(const BaseLocation&) = delete;
        BaseLocation& operator=(const BaseLocation&) = delete;

        std::unordered_set<Location_ptr> locations;

    private:
        std::string name;
        Event::EventHistory history;
        std::map<std::string, bool> attributes;

        std::vector<Actor::Individual_ptr> individuals;
        std::vector<Item::Item_ptr> items;


    };

} /* namespace Location */
#endif /* LOCATION_H_ */

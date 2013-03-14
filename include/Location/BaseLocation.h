/*
 * Location.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include "Individual/BaseIndividual.h"
#include "Item/BaseItem.h"
#include <memory>

namespace Location
{
	typedef std::shared_ptr<BaseLocation> Location_ptr;

	enum LocationType
	{
		VILLAGE_LOCATION,

		//insert before this
		LOCATION_ERROR,
		NUM_OF_LOCATIONS
	};

	class BaseLocation
	{
	public:
		virtual ~BaseLocation(){};

		virtual std::string getName() {return name;}

		virtual LocationType getLocationType(){return LocationType::LOCATION_ERROR;}

		virtual bool hasAttribute(std::string s) {return attributes.find(s) != attributes.end();}

		const Individual::IndividualList & getIndividuals() {return individuals;}
		const Item::ItemList & getItems() {return items;}
		const std::vector<Location_ptr> & getLocations() {return locations;}


		virtual void addItem(Item::Item_ptr i) { items.push_back(i); }

		virtual void operator+=(Item::Item_ptr rhs)	{items.push_back(rhs);}

		virtual void addIndividual(Individual::Individual_ptr i){individuals.push_back(i);}

		//Typically, locations are wrapped in shared_ptr so addIndividual is more appropriate
		virtual void operator+=(Individual::Individual_ptr rhs){individuals.push_back(rhs);	}

		virtual void addLocation(Location::Location_ptr l) { locations.push_back(l); }

		virtual void operator+=(Location::Location_ptr rhs) { locations.push_back(rhs); }


		//These should only be used by GoalCreator
		Location_ptr cameFrom;
		unsigned int distance;

	protected:
		BaseLocation(Location_ptr l) : distance(0) {locations.push_back(l);}
		BaseLocation(Location_ptr l, std::string _name) : distance(0), name(_name) {locations.push_back(l);}

	private:

		std::map<std::string, bool> attributes;
		std::string name;

		std::vector<Location_ptr> locations;
		std::vector<Individual::Individual_ptr> individuals;
		std::vector<Item::Item_ptr> items;


	};

} /* namespace Location */
#endif /* LOCATION_H_ */

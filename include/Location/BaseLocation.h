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


		virtual void addItem(Item::Item_ptr i) { items.push_back(i); }

		virtual void operator+=(Item::Item_ptr rhs)	{items.push_back(rhs);}

		virtual void addIndividual(Individual::Individual_ptr i){individuals.push_back(i);}

		//Typically, locations are wrapped in shared_ptr so addIndividual is more appropriate
		virtual void operator+=(Individual::Individual_ptr rhs){individuals.push_back(rhs);	}

	protected:
		BaseLocation(Location_ptr l) : parentLocation(l) {};
		BaseLocation(Location_ptr l, std::string _name) : parentLocation(l), name(_name){}

	private:

		Location_ptr parentLocation;
		std::vector<Location_ptr> childLocations;

		std::map<std::string, bool> attributes;
		std::string name;

		std::vector<Individual::Individual_ptr> individuals;
		std::vector<Item::Item_ptr> items;




	};

} /* namespace Location */
#endif /* LOCATION_H_ */

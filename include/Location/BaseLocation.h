/*
 * Location.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include "Individual/BaseIndividual.h"
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

		virtual std::string getName() = 0;
		virtual LocationType getLocationType() = 0;
		virtual void addIndividual(Individual::Individual_ptr) = 0;

	private:

	};

} /* namespace Location */
#endif /* LOCATION_H_ */

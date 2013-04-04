/*
 * Village.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef VILLAGE_H_
#define VILLAGE_H_

#include "Location/BaseLocation.h"
#include <vector>
#include <string>
#include <memory>

namespace Location {

	class Village: public BaseLocation
	{
	public:
		Village(std::string _name);

		LocationType getLocationType(){return Location::VILLAGE_LOCATION;}

	private:


	};

} /* namespace Location */
#endif /* VILLAGE_H_ */

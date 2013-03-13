/*
 * Village.cpp
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#include "Location/BaseLocation.h"
#include "Location/Village.h"

using namespace Location;

Village::Village(Location_ptr l) : BaseLocation(l)
{

}

Village::Village(Location_ptr l, std::string _name): BaseLocation(l, _name)
{

}

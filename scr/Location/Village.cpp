/*
 * Village.cpp
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#include "Location/BaseLocation.h"
#include "Location/Village.h"

using namespace Location;

Village::Village() : BaseLocation()
{
	setAttribute("habitable");
}

Village::Village(std::string _name): BaseLocation(_name)
{

}

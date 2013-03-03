/*
 * BirthEvent.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#include "Event/BirthEvent.h"

namespace Event {

BirthEvent::BirthEvent() :
		name("Birth")
{
}

Individual::Person * BirthEvent::run()
{
	return new Individual::Person();
}


} /* namespace Event */

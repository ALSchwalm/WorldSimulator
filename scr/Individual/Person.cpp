/*
 * Person.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#include "Individual/Person.h"

namespace Individual
{

Person::Person()
{
}

Person::Person(std::string s, Location_ptr location) : BaseIndividual(s, location)
{
}

}

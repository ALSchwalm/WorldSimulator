/*
 * Person.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#include "Individual/Person.h"

namespace Individual
{

Person::Person(std::string s, bool _isMale=true) : BaseIndividual(s, _isMale)
{
}

Person::Person(std::string s, Location_ptr location, bool _isMale=true) : BaseIndividual(s, location, _isMale)
{
}

}

/*
 * Person.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#include "Individual/Person.h"

using namespace Individual;

Person::Person() :
	age(0),
	name("")
{
}

Person::Person(std::string s) :
	age(0),
	name(s)
{
}


/*
 * main.cpp
 *
 *  Created on: Mar 1, 2013
 *      Author: Adam
 */

#include <iostream>
#include <vector>
#include "Individual/Person.h"
#include "Event/BirthEvent.h"

int main()
{
	using namespace Event;
	Individual::Person *p;

	BirthEvent * e = new BirthEvent();

	p = e->run();

	std::cout << "test" << p->getName();

	return 0;
}



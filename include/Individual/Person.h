/*
 * Person.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Event/Event.h"
#include "Event/BaseEvent.h"
#include "Individual/BaseIndividual.h"
#include <string>

namespace Individual
{
	class Person : public BaseIndividual
	{
	public:
		Person(std::string name, bool);
		Person(std::string name, Location_ptr location, bool);

		IndividualType getIndividualType() {return IndividualType::CITIZEN;}

	};
}
#endif /* PERSON_H_ */

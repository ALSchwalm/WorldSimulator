/*
 * Person.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef MERCHANT_H_
#define MERCHANT_H_

#include "Event/Event.h"
#include "Event/BaseEvent.h"
#include "Individual/BaseIndividual.h"
#include <string>

namespace Individual
{
	class Merchant : public BaseIndividual
	{
	public:
		Merchant(std::string name, bool);
		Merchant(std::string name, Location_ptr location, bool);

		IndividualType getIndividualType() override {return IndividualType::MERCHANT;}

	};
}
#endif

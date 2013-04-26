#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include "Item/BaseItem.h"
#include <vector>
#include <memory>

namespace Individual
{
	class BaseIndividual;

	enum IndividualType
	{
		BAKER,
		FISHER,
		BLACKSMITH,
		SOLDIER, //i.e.
		KING,
		MERCHANT, //i.e.
		ARTISAN,



		//insert before this
		INDIVIDUAL_ERROR,
		NUM_OF_INDIVIDUALS
	};

}

#endif

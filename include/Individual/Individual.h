#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include <vector>
#include <memory>

namespace Individual
{

	class BaseIndividual;

	typedef std::vector<std::shared_ptr<Individual::BaseIndividual>> IndividualList;

	enum IndividualType
	{
		CITIZEN,

		//insert before this
		INDIVIDUAL_ERROR,
		NUM_OF_INDIVIDUALS
	};

}

#endif

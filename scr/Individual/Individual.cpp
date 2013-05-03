
#include "Individual/Individual.h"
#include "Individual/BaseIndividual.h"
#include "Individual/SimpleIndividual.h"
#include "Utils/Config.h"

namespace Individual
{
	const unsigned int IndividualValues[]
	{
		Utils::Config::getInstance().getValue("OccupationRate", "BAKER_RATE")
	};

	static_assert(sizeof(IndividualValues)/sizeof(IndividualValues[0]) == NUM_OF_INDIVIDUALS, "IndividualType not given value in IndividualValues.");

	std::vector<Item::Item_ptr> getInitialItems(std::shared_ptr<BaseIndividual> individual)
	{
		std::vector<Item::Item_ptr> items;
		individual->addInitialItems(items);
		for (auto item : items)
			item->setOwner(individual);
		return items;
	}

	static std::shared_ptr<BaseIndividual> createIndividualFromType(IndividualType _type,
															std::string _name,
															Location::Location_ptr _location,
															bool _isMale)
	{
		switch(_type)
		{
		case BAKER:
			return std::make_shared<Baker>(_name, _location, _isMale);
		default:
			throw("Attempt to create individual from invalid enum.");
			return nullptr;
		}
	}

	std::shared_ptr<BaseIndividual> getRandomIndividual(std::string _name,
														Location::Location_ptr _location,
														bool _isMale)
	{
		IndividualType individual = static_cast<IndividualType>(rand()%1);
		return createIndividualFromType(individual, _name, _location, _isMale);
	}
}

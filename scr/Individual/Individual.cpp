
#include "Individual/Individual.h"
#include "Individual/BaseIndividual.h"

namespace Individual
{
	std::vector<Item::Item_ptr> getInitialItems(std::shared_ptr<BaseIndividual> i)
	{
		std::vector<Item::Item_ptr> items;

		switch(i->getIndividualType())
		{
		case BAKER:
			break;
		default:
			return items;
		}
		return items;
	}

}

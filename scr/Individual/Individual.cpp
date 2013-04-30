
#include "Individual/Individual.h"
#include "Individual/BaseIndividual.h"


namespace Individual
{
	std::vector<Item::Item_ptr> getInitialItems(std::shared_ptr<BaseIndividual> individual)
	{
		std::vector<Item::Item_ptr> items;
		individual->addInitialItems(items);
		for (auto item : items)
			item->setOwner(individual);
		return items;
	}
}

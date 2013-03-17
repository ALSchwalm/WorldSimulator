#include "Individual/BaseIndividual.h"
#include <algorithm>

using namespace Individual;

bool BaseIndividual::removeItem(Item::Item_ptr i)
{
	if (std::find(items.begin(), items.end(), i) == items.end())
	{
		return false;
	}
	else
	{
		items.erase(std::find(items.begin(), items.end(), i));
		return true;
	}

}

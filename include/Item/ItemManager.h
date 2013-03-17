#ifndef ITEMMANGER_H_
#define ITEMMANGER_H_

#include "Item/BaseItem.h"
#include "Individual/BaseIndividual.h"
#include "Location/BaseLocation.h"

namespace Item
{

	class ItemManager
	{
	public:
		ItemManager & getInstance();

		template <typename T, typename U>
		bool moveItem(Item_ptr, T source, U destination);

	private:
		ItemManager();
		~ItemManager(){}


	};

}

#endif

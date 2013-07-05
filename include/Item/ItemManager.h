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
		static ItemManager& getInstance();

		template <typename T, typename U>
		bool moveItem(Item_ptr item, T source, U destination)
		{
			if (source->removeItem(item))
			{
				destination->addItem(item);
				return true;
			}
			return false;
		}

	private:
		ItemManager();
		~ItemManager(){}


	};

}

#endif

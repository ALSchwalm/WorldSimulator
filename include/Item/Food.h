#ifndef FOOD_H_
#define FOOD_H_

#include <memory>
#include <map>
#include <string>
#include <vector>
#include "Item/BaseItem.h"

namespace Item
{



	enum FoodType
	{
		MUTTON,
		BACON,
		CORN,
		BEEF,

		NUM_OF_FOODS
	};

	const std::string foodTypeAsString[NUM_OF_FOODS] = {
		"Mutton",
		"Bacon",
		"Corn",
		"Beef"
	};

	class Food : public BaseItem
	{
	public:
		static Item_ptr getRandomFood();

		Food(FoodType _foodType) :
			BaseItem(foodTypeAsString[_foodType]),
			foodType(_foodType){};

		~Food(){};

	private:
		FoodType foodType;

	};

}

#endif

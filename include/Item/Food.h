#ifndef FOOD_H_
#define FOOD_H_

#include <memory>
#include <map>
#include <string>
#include <vector>
#include "Item/BaseItem.h"
#include "Skill/Skill.h"

namespace Item
{

	enum FoodType
	{
		MUTTON,
		BACON,
		CORN,
		BEEF,
		BREAD,
		WHEAT,

		NUM_OF_FOODS
	};

	const std::string foodTypeAsString[NUM_OF_FOODS] = {
		"Mutton",
		"Bacon",
		"Corn",
		"Beef",
		"Bread",
		"Wheat"
	};

	const std::map<FoodType, const Skill::skillMap> requiredFoodSkills
	{
		{MUTTON, 	{{Skill::COOKING, 	1.5f}}},

		{BACON, 	{{Skill::COOKING, 	2.0f}}},

		{CORN, 		{{Skill::COOKING, 	2.0f}}},

		{BEEF, 		{{Skill::COOKING, 	2.0f}}},

		{BREAD, 	{{Skill::COOKING, 	2.0f},
					 {Skill::BAKING,	1.5f}}}
	};


	/*
	 * This map maps a give food to the items required to make it.
	 * Unfortunately, tuples of size >1 cannot be implicitly constructed.
	 * The item type tells any function calling using the vector what to
	 * cast the first unsigned int to. This is clearly not an elegant
	 * approach. I am actively pursuing better alternatives.
	 */
	const std::map<FoodType, const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>> requiredFoodItems
	{
		{BREAD,		{std::make_tuple(FOOD, WHEAT, 1)}}
	};


	class Food : public BaseItem
	{
	public:
		static Item_ptr getRandomFood();
		static const Skill::skillMap & getRequiredSkill(FoodType t){return requiredFoodSkills.at(t);}
		static const std::vector<std::tuple<ItemType, unsigned int, unsigned int>> & getRequiredItems(FoodType t)
		{
			return requiredFoodItems.at(t);
		}
		const ItemType getItemType(){return FOOD;}

		Food(FoodType _foodType);
		~Food(){};

		const FoodType getFoodType() {return foodType;}

	private:
		const FoodType foodType;
	};




}

#endif

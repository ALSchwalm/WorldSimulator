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

		NUM_OF_FOODS
	};

	const std::string foodTypeAsString[NUM_OF_FOODS] = {
		"Mutton",
		"Bacon",
		"Corn",
		"Beef",
		"Bread"
	};

	const std::map<FoodType, const Skill::skillMap> requiredFoodSkills
	{
		{MUTTON, 	{{Skill::COOKING, 	1.5f}}},

		{BACON, 	{{Skill::COOKING, 	3.0f}}},

		{CORN, 		{{Skill::COOKING, 	3.0f}}},

		{BEEF, 		{{Skill::COOKING, 	3.0f}}},

		{BREAD, 	{{Skill::COOKING, 	3.0f},
					 {Skill::BAKING,	1.5f}}}
	};

	class Food : public BaseItem
	{
	public:
		static Item_ptr getRandomFood();
		static const Skill::skillMap & getRequiredSkill(FoodType t){return requiredFoodSkills.at(t);}
		Food(FoodType _foodType);

		~Food(){};

	private:
		const FoodType foodType;

	};

}

#endif

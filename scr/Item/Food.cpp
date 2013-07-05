
#include "Item/Food.h"
#include <cstdlib>

namespace Item
{


    Item_ptr Food::getRandomFood()
    {
        return std::make_shared<Food>( (FoodType) (rand() % FoodType::NUM_OF_FOODS));
    };

    Food::Food(FoodType _foodType) :
        BaseItem(foodTypeAsString[_foodType]),
        foodType(_foodType)
    {
        this->setAttribute("edible");
    }

}

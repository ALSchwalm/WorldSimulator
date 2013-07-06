
#include "Item/Food.h"
#include <cstdlib>

namespace Item
{

    template<foodType f>
    Item_ptr Food<f>::getRandomFood()
    {
        //return std::make_shared<Food>( (FoodType) (rand() % FoodType::NUM_OF_FOODS));
    };


}

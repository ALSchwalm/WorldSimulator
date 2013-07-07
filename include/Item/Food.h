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
    enum foodType
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

    const std::map<foodType, const Skill::skillMap> requiredFoodSkills
    {
       {MUTTON,    {{Skill::COOKING,   1.5f}}},

       {BACON,     {{Skill::COOKING,   2.0f}}},

       {CORN,      {{Skill::COOKING,   2.0f}}},

       {BEEF,      {{Skill::COOKING,   2.0f}}},

       {BREAD,     {{Skill::COOKING,   2.0f},
                       {Skill::BAKING, 1.5f}}}
    };

    /*
    * This map maps a give food to the items required to make it.
    * Unfortunately, tuples of size >1 cannot be implicitly constructed.
    * The item type tells any function using the vector what to
    * cast the first unsigned int to. This is clearly not an elegant
    * approach. I am actively pursuing better alternatives.
    */
    static const std::map<foodType, const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>> requiredFoodItems
    {
      {BREAD,     {std::make_tuple(FOOD, WHEAT, 1)}}
    };

    class BaseFood : public BaseItem
    {
    public:
        const ItemType getItemType() override {return FOOD;}
        const foodType getFoodType() {return foodtype;}

    protected:
        BaseFood(std::string _name, foodType _f) :
            BaseItem(_name),
            foodtype(_f)
        {}
    private:
        foodType foodtype;
    };

    template<foodType f>
    class Food : public BaseFood
    {
    public:
        typedef foodType type;
        typedef BaseFood baseType;

        static Item_ptr getRandomFood();

        static const Skill::skillMap& getRequiredSkill()
        {
            return requiredFoodSkills.at(f);
        }

        static const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>& getRequiredItems()
        {
           return requiredFoodItems.at(f);
        }

        const ItemType getItemType() override {return FOOD;}
        static constexpr ItemType getStaticItemType(){return FOOD;}


        Food() : BaseFood(foodTypeAsString[f], f)
        {
            this->setAttribute("edible");
        }

        ~Food(){};

    };
}

#endif

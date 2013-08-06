#include "WorldGen/PopulationGen.h"
#include "Location/World.h"
#include "Location/Location.h"
#include "Item/ItemFactory.h"
#include "Item/Container.h"
#include "Profession/SimpleProfession.h"
#include "Profession/Profession.h"
#include "Actor/Individual.h"
#include "Actor/ActorUtils.h"
#include "Utils/Markov.h"
#include "Utils/Config.h"
#include <cstdlib>
#include <memory>

namespace WorldGen
{
    namespace PopulationGen
    {


const unsigned int INITIAL_MAX_POPULATION = Utils::Config::getInstance().getValue("PopulationGen", "INITIAL_MAX_POPULATION");
const unsigned int INITIAL_MIN_POPULATION = Utils::Config::getInstance().getValue("PopulationGen", "INITIAL_MIN_POPULATION");

void seed()
{
    for (auto region : Location::World::getInstance()->getLocations())
    {
        for (auto city : region->getLocations())
        {
            if (city->hasAttribute("habitable"))
            {
                int population =  rand() % (INITIAL_MAX_POPULATION - INITIAL_MIN_POPULATION) + INITIAL_MIN_POPULATION;

                for (unsigned int family_size = 0; population > 0; population -= family_size)
                {
                    family_size = population % 5 + 1;

                    if (Item::getItemFactoryFromAttribute("habitable") != Item::itemFactories.end()) {
						auto&& factory = *Item::getItemFactoryFromAttribute("habitable");
						auto house = std::dynamic_pointer_cast<Item::Container>(factory->make());

						if (house.get()) {
							Actor::createFamily(family_size, house);

							city->addItem(house);
							Location::addLocations(city, house);
						}
						else {
							Actor::createFamily(family_size, city);
						}
                    }
                }
            }
        }
    }
}


    }
}

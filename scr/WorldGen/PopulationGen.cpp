#include "WorldGen/PopulationGen.h"
#include "Location/World.h"
#include "Location/Location.h"
#include "Item/Container.h"
#include "Individual/SimpleIndividual.h"
#include "Individual/BaseIndividual.h"
#include "Utils/Markov.h"
#include <cstdlib>
#include <memory>

namespace WorldGen
{
	namespace PopulationGen
	{


void seed()
{
	for (auto region : Location::World::getInstance()->getLocations())
	{
		for (auto city : region->getLocations())
		{
			if (city->hasAttribute("habitable"))
			{
				int population =  rand() % (INITIAL_MAX_POPULATION - INITIAL_MIN_POPULATION) + INITIAL_MIN_POPULATION;
				unsigned int family_size = 0;

				for (; population > 0; population -= family_size)
				{
					family_size = population % 5 + 1;

					auto house = std::make_shared<Item::Container>(Item::ContainerType::HOUSE);
					for (unsigned int i=0; i < family_size; ++i)
					{
						house->addIndividual(std::make_shared<Individual::Baker>(Utils::Markov::getInstance().getProperWord(), city, rand()%2));
					}
					city->addItem(house);
					Location::addLocations(city, house);
				}
			}
		}
	}
}


	}
}

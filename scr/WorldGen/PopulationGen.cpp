#include "WorldGen/PopulationGen.h"
#include "Location/World.h"
#include "Location/Location.h"
#include "Item/Container.h"
#include "Individual/SimpleIndividual.h"
#include "Individual/BaseIndividual.h"
#include "Individual/Individual.h"
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

					auto house = std::make_shared<Item::Container>(Item::ContainerType::HOUSE);
					for (unsigned int i=0; i < family_size; ++i)
					{
						auto newIndividual = Individual::getRandomIndividual(Utils::Markov::getInstance().getProperWord(), city, rand()%2);
						house->addIndividual(newIndividual);
						for (auto item : Individual::getInitialItems(newIndividual))
							house->addItem(item);
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

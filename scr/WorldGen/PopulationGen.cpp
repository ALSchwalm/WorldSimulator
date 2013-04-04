#include "WorldGen/PopulationGen.h"
#include "Location/World.h"
#include "Individual/Person.h"
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
				for (unsigned int i=0; i < rand() % (INITIAL_MAX_POPULATION - INITIAL_MIN_POPULATION) + INITIAL_MIN_POPULATION; ++i)
				{
					city->addIndividual(std::make_shared<Individual::Person>(Utils::Markov::getInstance().getProperWord()));
				}
			}
		}
	}
}


	}
}

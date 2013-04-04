#include "WorldGen/PopulationGen.h"
#include "Location/World.h"
#include "Individual/Person.h"
#include "Utils/Markov.h"
#include <cstdlib>
#include <memory>

using namespace WorldGen;

PopulationGen & PopulationGen::getInstance()
{
	static PopulationGen populationGen;
	return populationGen;
}

void PopulationGen::seed()
{
	for (auto region : Location::World::getInstance()->getLocations())
	{
		for (auto city : region->getLocations())
		{
			if (city->hasAttribute("habitable"))
			{
				for (int i=0; i < rand()%200 + 100; ++i)
				{
					city->addIndividual(std::make_shared<Individual::Person>(Utils::Markov::getInstance().getProperWord()));
				}
			}
		}
	}
}

PopulationGen::PopulationGen()
{

}

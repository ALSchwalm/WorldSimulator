#ifndef POPULATIONGEN_H_
#define POPULATIONGEN_H_


#include "Location/BaseLocation.h"

namespace WorldGen
{
	namespace PopulationGen
	{
		void seed();

		const unsigned int INITIAL_MAX_POPULATION = 300; //population per city
		const unsigned int INITIAL_MIN_POPULATION = 100;

	};
}

#endif

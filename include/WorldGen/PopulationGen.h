#ifndef POPULATIONGEN_H_
#define POPULATIONGEN_H_


#include "Location/BaseLocation.h"

namespace WorldGen
{
	class PopulationGen
	{
	public:
		static PopulationGen & getInstance();
		static void seed();

	private:
		PopulationGen();

	};
}

#endif

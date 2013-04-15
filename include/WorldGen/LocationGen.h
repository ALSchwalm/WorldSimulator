#ifndef LOCATIONGEN_H_
#define LOCATIONGEN_H_


#include "Location/BaseLocation.h"

namespace WorldGen
{
	namespace LocationGen
	{
		void seed();
		extern const unsigned int MAX_REGIONS;
		extern const unsigned int MIN_REGIONS;

		extern const unsigned int MAX_CITIES_PER_REGION;
		extern const unsigned int MIN_CITIES_PER_REGION;
	};
}

#endif

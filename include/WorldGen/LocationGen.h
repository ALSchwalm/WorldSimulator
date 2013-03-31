#ifndef LOCATIONGEN_H_
#define LOCATIONGEN_H_


#include "Location/BaseLocation.h"



namespace WorldGen
{
	class LocationGen
	{
	public:
		static LocationGen & getInstance();
		static void seed();

	private:
		LocationGen();

	};
}

#endif

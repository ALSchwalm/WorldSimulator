#ifndef LOCATIONMANGER_H_
#define LOCATIONMANGER_H_

#include "Location/BaseLocation.h"

namespace Location
{

	class LocationManager
	{
	public:
		static LocationManager & getInstance();

		void addLocation(Location_ptr locationOne, Location_ptr locationTwo)
		{
			locationOne->addLocation(locationTwo);
			locationTwo->addLocation(locationOne);
		}

	private:
		LocationManager(){};
		~LocationManager(){}


	};

}

#endif

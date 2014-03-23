#ifndef LOCATION_H_
#define LOCATION_H_

#include "Location/BaseLocation.h"

namespace Location
{

    inline void connectLocations(Location_ptr locationOne, Location_ptr locationTwo)
    {
        locationOne->addLocation(locationTwo);
        locationTwo->addLocation(locationOne);
    }

    inline void separateLocations(Location_ptr locationOne, Location_ptr locationTwo)
    {
        locationOne->removeLocation(locationTwo);
        locationTwo->removeLocation(locationOne);
    }

}

#endif

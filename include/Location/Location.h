#ifndef LOCATION_H_
#define LOCATION_H_

#include "Location/BaseLocation.h"

namespace Location
{

    inline void addLocations(Location_ptr locationOne, Location_ptr locationTwo)
    {
        locationOne->addLocation(locationTwo);
        locationTwo->addLocation(locationOne);
    }

}

#endif

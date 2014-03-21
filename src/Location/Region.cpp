#include "Location/BaseLocation.h"
#include "Location/Region.h"
#include "Utils/Utils.h"

using namespace Location;


RegionType Region::getRandomRegionType()
{
    return static_cast<RegionType>(Utils::uniform(0, RegionType::NUM_OF_REGIONS));
}

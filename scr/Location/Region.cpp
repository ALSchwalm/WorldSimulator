#include "Location/BaseLocation.h"
#include "Location/Region.h"

#include <cstdlib>

using namespace Location;


RegionType Region::getRandomRegionType()
{
	return static_cast<RegionType>(rand() % RegionType::NUM_OF_REGIONS);
}

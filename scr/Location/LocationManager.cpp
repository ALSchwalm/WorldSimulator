
#include "Location/LocationManager.h"

using namespace Location;

LocationManager & LocationManager::getInstance()
{
	static LocationManager manager;
	return manager;
}

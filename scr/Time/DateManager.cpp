
#include "Time/DateManager.h"

using namespace Time;

DateManager & DateManager::getInstance()
{
	static DateManager d;
	return d;
}

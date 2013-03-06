
#include "Time/DateManager.h"

using namespace Time;

DateManager & DateManager::getInstance()
{
	static DateManager d;
	return d;
}

DateManager::DateManager() :
		now (Date(0, Month::January, Day::Sunday))
{
}

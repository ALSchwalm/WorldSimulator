
#include "Time/TimeManager.h"
#include <time.h>
#include <windows.h>

#include <iostream> //TODO remove this

using namespace Time;

TimeManager & TimeManager::getInstance()
{
	static TimeManager timeManager;
	return timeManager;
}



TimeManager::TimeManager()
{
    this->dTimeLastFrame = ((float)clock())/CLOCKS_PER_SEC; //Damn son, look at all these floatin clocks
    this->dTimeLastFPS = ((float)clock())/CLOCKS_PER_SEC;
    this->dTimeLastTick = ((float)clock())/CLOCKS_PER_SEC;
    this->dTimeRemainder = 0;
}

void TimeManager::capFPS()
{
    double dCurrentTime = ((float)clock())/CLOCKS_PER_SEC;
    if (  (dCurrentTime - dTimeLastFrame) < 1.0f/MAX_FPS ) //inverse of FPS is SPF, which is the unit of deltatime, as capFPS is called every frame
    {
        Sleep( ((1.0f/MAX_FPS) - (dCurrentTime - dTimeLastFrame)) *1000);
    }
    this->dTimeLastFrame = ((float)clock())/CLOCKS_PER_SEC;
}

int TimeManager::getFPS()
{
    double dCurrentTime = ((float)clock())/CLOCKS_PER_SEC;
    double dDeltaTime = (dCurrentTime - dTimeLastFPS);
    this->dTimeLastFPS = dCurrentTime;
    return 1 / dDeltaTime; //the reverse of the logic for capFPS, inverse SPF is FPS
}

void TimeManager::tick()
{
    double dCurrentTime = ((float)clock())/CLOCKS_PER_SEC;

    dTimeRemainder += (dCurrentTime - dTimeLastTick);

    if (dTimeRemainder > 1.0f / DAYS_PER_SECOND)
    {
        unsigned int iTempDivisor = dTimeRemainder  / (1.0f / DAYS_PER_SECOND);
        for (unsigned int i = 0; i < iTempDivisor; i++)
        {
        	std::cout << now() << std::endl;
        	DateManager::getInstance().nextDay();
        }
        dTimeRemainder -= iTempDivisor * (1.0f / DAYS_PER_SECOND);

    }
    this->dTimeLastTick = ((float)clock())/CLOCKS_PER_SEC;
}

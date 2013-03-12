
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
    timeLastFrame = ((float)clock())/CLOCKS_PER_SEC;
    timeLastFPS = ((float)clock())/CLOCKS_PER_SEC;
    timeLastTick = ((float)clock())/CLOCKS_PER_SEC;
    timeRemainder = 0;
}

void TimeManager::capFPS()
{
    double currentTime = ((float)clock())/CLOCKS_PER_SEC;
    if (  (currentTime - timeLastFrame) < 1.0f/MAX_FPS ) //inverse of FPS is SPF, which is the unit of deltatime, as capFPS is called every frame
    {
        Sleep( ((1.0f/MAX_FPS) - (currentTime - timeLastFrame)) *1000);
    }
    timeLastFrame = ((float)clock())/CLOCKS_PER_SEC;
}

int TimeManager::getFPS()
{
    double currentTime = ((float)clock())/CLOCKS_PER_SEC;
    double deltaTime = (currentTime - timeLastFPS);
    timeLastFPS = currentTime;
    return 1 / deltaTime; //the reverse of the logic for capFPS, inverse SPF is FPS
}

void TimeManager::tick()
{
    double dCurrentTime = ((float)clock())/CLOCKS_PER_SEC;

    timeRemainder += (dCurrentTime - timeLastTick);

    if (timeRemainder > 1.0f / MINUTES_PER_SECOND)
    {
        unsigned int tempDivisor = timeRemainder  / (1.0f / MINUTES_PER_SECOND);
        for (unsigned int i = 0; i < tempDivisor; i++)
        {
        	std::cout << now() << std::endl;
        	DateManager::getInstance().nextMinute();
        }
        timeRemainder -= tempDivisor * (1.0f / MINUTES_PER_SECOND);

    }
    timeLastTick = ((float)clock())/CLOCKS_PER_SEC;
}

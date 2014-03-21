#include "Time/TimeManager.h"
#include "Utils/Config.h"
#include <thread>

using namespace Time;

TimeManager & TimeManager::getInstance()
{
    static TimeManager timeManager;
    return timeManager;
}

const unsigned int TimeManager::REFRESH_RATE =
    Utils::Config::getInstance().getValue("Time.REFRESH_RATE");

const system_clock::duration TimeManager::REFRESH_TIME =
    std::chrono::milliseconds((long)(1.0/TimeManager::REFRESH_RATE * 1000));

const unsigned int TimeManager::MINUTES_PER_SECOND =
    Utils::Config::getInstance().getValue("Time.MINUTES_PER_SECOND");


TimeManager::TimeManager() :
    timeLastFrame(system_clock::now()),
    timeLastTick(system_clock::now()) {}

void TimeManager::capRefresh()
{
    auto currentTime = system_clock::now();

    if ((currentTime - timeLastFrame) <  REFRESH_TIME)
    {
        auto duration = REFRESH_TIME - (currentTime - timeLastFrame);
        std::this_thread::sleep_for(duration);
    }
    timeLastFrame = system_clock::now();
}

void TimeManager::tick()
{
    auto currentTime = system_clock::now();

    timeRemainder += (currentTime - timeLastTick);

    if (timeRemainder.count() > 1.0f / MINUTES_PER_SECOND)
    {
        unsigned int minutesPassed = timeRemainder  / milliseconds((long)(1.0f/MINUTES_PER_SECOND*1000));
        for (unsigned int i = 0; i < minutesPassed; i++)
        {
            DateManager::getInstance().nextMinute();
        }
        timeRemainder -= milliseconds((long)(minutesPassed * (1.0f / MINUTES_PER_SECOND) * 1000));

    }
    timeLastTick = system_clock::now();
}

#ifndef TIMEMANAGER_H_
#define TIMEMANAGER_H_

#include "Time/DateManager.h"
#include <chrono>

namespace Time
{

    using namespace std::chrono;

    class TimeManager
    {


    public:

        static TimeManager& getInstance();

        void capRefresh();
        void tick();

    private:
        TimeManager();

        system_clock::time_point timeLastFrame;
        system_clock::time_point timeLastTick;
        system_clock::duration timeRemainder;

        static const unsigned int REFRESH_RATE;
        static const system_clock::duration REFRESH_TIME;
        static const unsigned int MINUTES_PER_SECOND;

    };
}

#endif

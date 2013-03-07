#ifndef TIMEMANAGER_H_
#define TIMEMANAGER_H_

#include "Utils/Global.h"
#include "Time/DateManager.h"

namespace Time
{
	class TimeManager
	{
	public:

		static TimeManager & getInstance();

        void capFPS(); //one of these is off by a bit. 2 FPS cap -> 2 actual FPS, but 100 FPS cap -> 111 actual FPS
        int getFPS();
        void tick();

	private:
        TimeManager();

        double dTimeLastFrame;
        double dTimeLastFPS;
        double dTimeLastTick;
        double dTimeRemainder;

        const unsigned int MAX_FPS = 100;
        const unsigned int DAYS_PER_SECOND = 5;
	};
}

#endif

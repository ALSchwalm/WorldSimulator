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

        double timeLastFrame;
        double timeLastFPS;
        double timeLastTick;
        double timeRemainder;

        const unsigned int MAX_FPS = 100;
        const unsigned int MINUTES_PER_SECOND = 50;
	};
}

#endif

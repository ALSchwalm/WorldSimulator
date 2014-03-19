#ifndef DATEMANAGER_H_
#define DATEMANAGER_H_

#include "Time/Date.h"
#include <string>
#include <ctime>

namespace Time
{
    class DateManager {
    public:
        static DateManager& getInstance();

        void nextMinute();

        Date now();

    private:
        DateManager();
        Date date;
    };

    //shorthand for Time::DateManager::getInstance().now
    inline Date now() {
        return DateManager::getInstance().now();
    }
}


#endif

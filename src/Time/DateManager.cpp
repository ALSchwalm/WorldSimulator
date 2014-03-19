
#include "Time/DateManager.h"

using namespace Time;

DateManager & DateManager::getInstance()
{
    static DateManager d;
    return d;
}

DateManager::DateManager() :
        date()
{

}

void DateManager::nextMinute() {
    date.setMinute(date.getMinute()+ 1);
}

Date DateManager::now() {
    return date;
}

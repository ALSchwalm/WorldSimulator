
#include "Time/DateManager.h"

using namespace Time;

DateManager & DateManager::getInstance()
{
    static DateManager d;
    return d;
}

DateManager::DateManager() :
        now (Date(1, Month::January, Day::Sunday))
{

}

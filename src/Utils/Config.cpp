
#include "Utils/Config.h"

using namespace Utils;

Config & Config::getInstance()
{
    static Config c;
    return c;
}

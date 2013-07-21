#ifndef UTILS_H
#define UTILS_H

#include <sstream>

namespace Utils
{

    template <typename T>
    std::string numberToString (T num)
    {
        std::ostringstream ss;
        ss << num;
        return ss.str();
    }

}

#endif

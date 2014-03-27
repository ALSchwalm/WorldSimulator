#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <cassert>

namespace Utils
{
    static std::random_device rd;
    static std::mt19937 rng(rd());

    inline int uniform(int lower, int upper) {
        assert(upper-1 >= lower);
        std::uniform_int_distribution<> dist(lower, upper-1);
        return dist(rng);
    }

    namespace Logging
    {
        void initialize();
    }
}

#endif

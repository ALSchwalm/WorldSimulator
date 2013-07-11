
#ifndef ACTORUTILS_H_
#define ACTORUTILS_H_

#include "Actor/Individual.h"
#include "Profession/Profession.h"
#include "Location/BaseLocation.h"
#include <vector>

namespace Actor
{
    const std::vector<Individual_ptr> createFamily(unsigned int size=4,
                                                    Location::Location_ptr l=nullptr);

}

#endif

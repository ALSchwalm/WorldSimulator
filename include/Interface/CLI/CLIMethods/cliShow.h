#ifndef CLISHOW_H_
#define CLISHOW_H_

#include "Interface/GeneralView.h"
#include "Interface/Interface.h"
#include "Location/World.h"
#include "Location/BaseLocation.h"
#include <vector>
#include <memory>

namespace Interface
{
    namespace CLI
    {
        inline bool cliViewWorld()
        {
            displayView = std::make_shared<GeneralView<Location::Location_ptr> >(Location::World::getInstance());
            return true;
        };

        bool cliViewLocation();

        bool cliShowLocationRange();
        bool cliShowItemRange();
        bool cliShowIndividualRange();
    }
}

#endif

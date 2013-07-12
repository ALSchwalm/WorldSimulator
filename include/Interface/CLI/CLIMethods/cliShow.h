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
        inline bool cliShowWorld()
        {
            displayView = std::make_shared<GeneralView<Location::Location_ptr> >(Location::World::getInstance());
            return true;
        };

        bool cliShowLocation();

        bool cliShowLocationRange();
        bool cliShowItemRange();
    }
}

#endif

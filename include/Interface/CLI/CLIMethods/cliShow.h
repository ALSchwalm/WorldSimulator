#ifndef CLISHOW_H_
#define CLISHOW_H_

#include "Interface/GeneralView.h"
#include "Interface/Interface.h"
#include "Location/World.h"
#include <vector>
#include <memory>

namespace Interface
{
    namespace CLI
    {
        inline bool cliViewWorld()
        {
            displayView = std::make_shared<GeneralView<Location::Location_ptr> >(Location::World::getInstance());
            currentContext = Context::LOCATION;
            return true;
        };

        template<Context c>
        bool cliViewLocation();

        template<> bool cliViewLocation<Context::INDIVIDUAL>();
        template<> bool cliViewLocation<Context::LOCATION>();


        template<Context c>
        bool cliViewIndividual();

        template<> bool cliViewIndividual<Context::INDIVIDUAL>();
        template<> bool cliViewIndividual<Context::LOCATION>();

        bool cliShowLocationRange();

        template<Context c>
        bool cliShowItemRange();

        template<> bool cliShowItemRange<Context::INDIVIDUAL>();
        template<> bool cliShowItemRange<Context::LOCATION>();

        bool cliShowIndividualRange();

        bool cliShowInfo();
    }
}

#endif

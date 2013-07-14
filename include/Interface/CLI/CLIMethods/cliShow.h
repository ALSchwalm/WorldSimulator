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
            return true;
        };

        //template<typename T>
        bool cliViewLocation();

        template<Context c>
        bool cliViewIndividual();

        template<> bool cliViewIndividual<Context::INDIVIDUAL>();
        template<> bool cliViewIndividual<Context::LOCATION>();

        //template<typename T>
        bool cliShowLocationRange();

        //template<typename T>
        bool cliShowItemRange();

        //template<typename T>
        bool cliShowIndividualRange();

        bool cliShowInfo();
    }
}

#endif

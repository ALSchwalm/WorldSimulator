
#include "Interface/CLI/CLIMethods/cliShow.h"
#include "Interface/CLI/Commands.h"
#include "Interface/CLI/CLI.h"
#include "Location/BaseLocation.h"
#include "Actor/Individual.h"
#include "Interface/RangeView.h"
#include <memory>

namespace Interface
{
    namespace CLI
    {

        bool cliShowInfo()
        {
            return true;
        }
        inline bool cliViewLocation()
        {
            auto view = dynamic_cast<View<Location::Location_ptr>* >(displayView.get());
            for (auto location : view->viewSubject->getLocations())
            {
                if (location->getName() == currentCommand.args[0])
                {
                    displayView = std::make_shared<GeneralView<Location::Location_ptr> >(location);
                    currentContext = Context::INDIVIDUAL;
                    return true;
                }
            }
            return false;
        }

        template<>
        bool cliViewIndividual<Context::INDIVIDUAL>()
        {
            auto individualView = dynamic_cast<View<Actor::Individual_ptr>* >(displayView.get());

            if (!individualView)
                return false;

            for (auto individual : individualView->viewSubject->getCurrentLocation()->getIndividuals())
            {
                if (individual->getName() == currentCommand.args[0])
                {
                    displayView = std::make_shared<GeneralView<Actor::Individual_ptr> >(individual);
                    currentContext = Context::INDIVIDUAL;
                    return true;
                }
            }
            return false;
        }

        template<>
        bool cliViewIndividual<Context::LOCATION>()
        {
            auto locationView = dynamic_cast<View<Location::Location_ptr>* >(displayView.get());

            if (!locationView)
                return false;

            for (auto individual : locationView->viewSubject->getIndividuals())
            {
                if (individual->getName() == currentCommand.args[0])
                {
                    displayView = std::make_shared<GeneralView<Actor::Individual_ptr> >(individual);
                    currentContext = Context::INDIVIDUAL;
                    return true;
                }
            }
            return false;
        }


        inline bool cliShowLocationRange()
        {
            /*
             * We know this dynamic cast is valid because these commands are protected by 'context'.
             * That is, the cliShowLocaiton command can only be called when the view is a location_ptr.
             */
            auto view = dynamic_cast<View<Location::Location_ptr>* >(displayView.get());

            /*
             * RangeView is a class template. The first parameter is the type of the viewSubject,
             * while the second type is what about the viewSubject you want to show.
             */
            displayView = std::make_shared<RangeView<Location::Location_ptr, Location::Location_ptr> >(view->viewSubject);
            return true;
        }

        inline bool cliShowItemRange()
        {
            auto view = dynamic_cast<View<Location::Location_ptr>* >(displayView.get());
            displayView = std::make_shared<RangeView<Location::Location_ptr, Item::Item_ptr> >(view->viewSubject);
            return true;
        }

        inline bool cliShowIndividualRange()
        {
            auto view = dynamic_cast<View<Location::Location_ptr>* >(displayView.get());
            displayView = std::make_shared<RangeView<Location::Location_ptr, Actor::Individual_ptr> >(view->viewSubject);
            return true;
        }

    }
}

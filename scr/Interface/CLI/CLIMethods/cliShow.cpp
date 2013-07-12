
#include "Interface/CLI/CLIMethods/cliShow.h"
#include "Interface/CLI/Commands.h"
#include "Interface/CLI/CLI.h"
#include "Location/BaseLocation.h"
#include "Interface/RangeView.h"
#include <memory>

namespace Interface
{
    namespace CLI
    {

        bool cliShowLocation()
        {
            auto view = dynamic_cast<View<Location::Location_ptr>* >(displayView.get());
            for (auto location : view->viewSubject->getLocations())
            {
                if (location->getName() == currentCommand.args[0])
                {
                    displayView = std::make_shared<GeneralView<Location::Location_ptr> >(location);
                    return true;
                }
            }
            return false;
        }

        bool cliShowLocationRange()
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

        bool cliShowItemRange()
        {
            auto view = dynamic_cast<View<Location::Location_ptr>* >(displayView.get());
            displayView = std::make_shared<RangeView<Location::Location_ptr, Item::Item_ptr> >(view->viewSubject);
            return true;
        }

    }
}

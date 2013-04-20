
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
			auto view = dynamic_cast<View<Location::Location_ptr>* >(displayView.get());
			displayView = std::make_shared<RangeView<Location::Location_ptr> >(view->viewSubject);
			return true;
		}

	}
}

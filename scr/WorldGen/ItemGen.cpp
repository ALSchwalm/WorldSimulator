
#include "WorldGen/ItemGen.h"
#include "Item/Container.h"
#include "Location/World.h"
#include "Location/Location.h"
#include <memory>

using namespace WorldGen;

void seed()
{
    for (auto location : Location::World::getInstance()->getLocations())
    {
        for (auto region : location->getLocations())
        {
            auto house = std::make_shared<Item::Container<Item::HOUSE>>();
            Location::addLocations(region, house);
        }
    }

}

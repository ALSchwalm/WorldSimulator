
#include "WorldGen/ItemGen.h"
#include "Item/Container.h"
#include "Location/World.h"
#include "Location/Location.h"
#include <memory>
#include <unordered_set>
#include <list>

namespace WorldGen
{
    namespace ItemGen
    {
        void seed()
        {
            std::list<Location::Location_ptr> openset;
            std::unordered_set<Location::Location_ptr> closedset;

            openset.push_back(Location::World::getInstance());

            for (auto location : openset)
            {
                closedset.insert(location);
                for (auto possibleLocation : location->getLocations())
                {
                    if (closedset.find(possibleLocation) == closedset.end() &&
                            std::find(openset.begin(), openset.end(), possibleLocation) == openset.end())
                    {
                        openset.push_back(possibleLocation);
                    }
                }


                for (auto individual : location->getIndividuals())
                {
                    for (auto item : individual->getInitialItems())
                    {
                        item->setOwner(individual);
                        location->addItem(item);
                    }
                }


            }

        }
    }
}



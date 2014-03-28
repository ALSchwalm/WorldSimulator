#ifndef WORLD_H_
#define WORLD_H_

#include "Location/BaseLocation.h"


namespace Location
{

    class World : public BaseLocation
    {
    public:
        World();
        ~World();
        static Location_ptr getInstance();

        LocationType getLocationType() const {return LocationType::WORLD;}

        //override these functions to throw errors if they are called on a "world"
        void addItem(Item::Item_ptr) override;
        void addIndividual(Actor::Individual_ptr) override;

    private:


    };


}

#endif

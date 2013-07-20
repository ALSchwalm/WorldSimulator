#ifndef DISEASE_H_
#define DISEASE_H_

#include "Actor/Individual.h"
#include "Utils/Markov.h"
#include <string>
#include <cstdlib>

namespace Actor
{


    class Disease
    {
    public:
        Disease(std::string _name, unsigned int _spreadFactor, std::array<unsigned int, NUM_OF_STATS> _effects) :
            name(_name),
            spreadFactor(_spreadFactor),
            effects(_effects)
        {
        }

        Disease(std::string _name, unsigned int _spreadFactor) :
            name(_name),
            spreadFactor(_spreadFactor)
        {
            for (unsigned int i=0; i < NUM_OF_STATS; ++i)
                effects[i] = -1*(rand()%10);
        }

        Disease() : Disease(Utils::Markov::getInstance().getProperWord(),
                rand()%10){}

        const std::array<unsigned int, NUM_OF_STATS>& getEffects() const {return effects;}
        unsigned int getEffectOn(Stats stat) const {return effects[stat];}
        unsigned int getSpreadFactor() const {return spreadFactor;}
        std::string getName() const {return name;}

    private:
        const std::string name;
        const unsigned int spreadFactor;
        std::array<unsigned int, NUM_OF_STATS> effects;

    };
}
#endif

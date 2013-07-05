#ifndef MOUTAIN_H_
#define MOUTAIN_H_

#include "Location/Terrain/BaseTerrain.h"

namespace Location
{
    namespace Terrain {

        class Moutain: public BaseTerrain
        {
        public:
            Moutain(std::string _name);

            TerrainType getTerrainType(){return Terrain::MOUTAIN_TERRAIN;}

        private:


        };

    }
}
#endif

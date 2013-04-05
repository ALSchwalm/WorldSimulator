
#ifndef BASETERRAIN_H_
#define BASETERRAIN_H_

#include "Location/BaseLocation.h"
#include <memory>
#include <string>

namespace Location
{
	namespace Terrain
	{

		enum TerrainType
		{
			FOREST_TERRAIN,
			MOUTAIN_TERRAIN,

			ERROR_TERRAIN,
			NUM_OF_TERRAIN
		};

		class BaseTerrain: public BaseLocation
		{
		public:
			virtual ~BaseTerrain(){}

			virtual TerrainType getTerrainType()=0;
			LocationType getLocationType(){return LocationType::TERRAIN;}

		protected:
			BaseTerrain(std::string _name) :
				BaseLocation(_name)
			{}


		private:

		};

		typedef std::shared_ptr<BaseTerrain> Terrain_ptr;
	}
}
#endif

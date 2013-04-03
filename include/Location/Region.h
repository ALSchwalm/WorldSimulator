#ifndef REGION_H_
#define REGION_H_

#include "Location/BaseLocation.h"
#include "Location/World.h"
#include <vector>
#include <string>
#include <memory>

#include <iostream> //TODO remove this

namespace Location {

	enum RegionType
	{
		DESERT,
		FOREST,
		PLAINS,

		NUM_OF_REGIONS
	};

	class Region: public BaseLocation
	{
	public:
		static RegionType getRandomRegionType();

		Region(std::string _name, RegionType _regionType = RegionType::PLAINS) :
			BaseLocation(_name),
			regionType(_regionType)
			{};

		LocationType getLocationType(){return Location::REGION_LOCATION;}
		RegionType getRegionType() {return regionType;}


	private:
		RegionType regionType;

	};

} /* namespace Location */
#endif

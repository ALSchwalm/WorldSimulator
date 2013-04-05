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

		LocationType getLocationType(){return LocationType::WORLD;}

		//override these functions to throw errors if they are called on a "world"
		void addItem(Item::Item_ptr i);
		void operator+=(Item::Item_ptr rhs);
		void addIndividual(Individual::Individual_ptr i);
		void operator+=(Individual::Individual_ptr rhs);


	private:


	};


}

#endif

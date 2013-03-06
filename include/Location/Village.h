/*
 * Village.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef VILLAGE_H_
#define VILLAGE_H_

#include "Location/BaseLocation.h"
#include <vector>
#include <string>
#include <memory>

namespace Location {

	class Village: public BaseLocation
	{
	public:
		Village();
		Village(std::string _name);


		std::string getName() {return name;}
		LocationType getLocationType(){return Location::VILLAGE_LOCATION;}

		void addIndividual(std::shared_ptr<Individual::BaseIndividual> i) {
			individuals.push_back(i);
		}

		const Individual::IndividualList & getIndividuals() {return individuals;}


	private:
		typedef std::vector<std::shared_ptr<Individual::BaseIndividual>> IndividualList;

		Individual::IndividualList individuals;
		std::string name;

	};

} /* namespace Location */
#endif /* VILLAGE_H_ */

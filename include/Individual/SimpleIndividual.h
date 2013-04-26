#ifndef SIMPLEINDIVIDUAL_H_
#define SIMPLEINDIVIDUAL_H_

#include "Individual/BaseIndividual.h"
#include "Individual/Artisan.h"
#include "Individual/Merchant.h"
#include "Location/BaseLocation.h"

namespace Individual
{
	class Baker : public Artisan, public Merchant
	{
	public:
		Baker(std::string _name, Location_ptr _location, bool _isMale=true) :
			BaseIndividual(_name, _location, _isMale),
			Artisan(_name, _location, _isMale),
			Merchant(_name, _location, _isMale)
		{}

		IndividualType getIndividualType() override {return IndividualType::BAKER;}
		void addInitialItems(std::vector<Item::Item_ptr> &) override {};
		Item::Item_ptr createItem(){return NULL;}
	};





}
#endif

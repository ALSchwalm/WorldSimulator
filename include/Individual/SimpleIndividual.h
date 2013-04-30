#ifndef SIMPLEINDIVIDUAL_H_
#define SIMPLEINDIVIDUAL_H_

#include "Individual/BaseIndividual.h"
#include "Individual/Artisan.h"
#include "Individual/Merchant.h"
#include "Location/BaseLocation.h"
#include "Item/Food.h"
#include "Skill/Skill.h"

namespace Individual
{
	class Baker : public Artisan, public Merchant
	{
	public:
		Baker(std::string _name, Location_ptr _location, bool _isMale=true) :
			BaseIndividual(_name, _location, _isMale),
			Artisan(_name, _location, _isMale),
			Merchant(_name, _location, _isMale)
		{
			setSkill(Skill::BAKING, 5.0f);
			setSkill(Skill::COOKING, 5.0f);
		}
		Baker(std::string _name, bool _isMale=true) :
			BaseIndividual(_name, _isMale),
			Artisan(_name, _isMale),
			Merchant(_name, _isMale)
		{
			setSkill(Skill::BAKING, 5.0f);
			setSkill(Skill::COOKING, 5.0f);
		}

		IndividualType getIndividualType() override {return IndividualType::BAKER;}

		void addInitialItems(std::vector<Item::Item_ptr> items)
		{
			items.push_back(std::make_shared<Item::Food>(Item::BREAD));
		};

	};





}
#endif

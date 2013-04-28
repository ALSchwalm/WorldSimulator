#ifndef WEAPON_H_
#define WEAPON_H_

#include "Item/BaseItem.h"
#include "Skill/Skill.h"
#include <memory>
#include <map>
#include <string>
#include <vector>

namespace Item
{
enum WeaponType
{
	SWORD,
	BOW,

	NUM_OF_WEAPONS
};

const std::string weaponTypeAsString[NUM_OF_WEAPONS] = {

};

const Skill::skillMap requiredWeaponSkills[NUM_OF_WEAPONS]
{
	{//SWORD
		{Skill::BLACKSMITHING, 	3.0f}
	},

	{//BOW
		{Skill::WOODWORKING, 	3.0f}
	},

};



	class Weapon : public BaseItem
	{
	public:
		Weapon(WeaponType _weaponType) : weaponType(_weaponType){}
		Weapon(std::string _name, WeaponType _weaponType) :
			BaseItem(_name),
			weaponType(_weaponType)
		{}
		Weapon(Individual::Individual_ptr _owner, WeaponType _weaponType) :
			BaseItem(_owner) ,
			weaponType(_weaponType)
		{}
		Weapon(std::string _name, Individual::Individual_ptr _owner, WeaponType _weaponType ) :
			BaseItem(_name, _owner),
			weaponType(_weaponType)
		{}

		~Weapon(){};

		const Skill::skillMap & getRequiredSkill() {return requiredWeaponSkills[weaponType];}

	private:
		WeaponType weaponType;

	};

}

#endif

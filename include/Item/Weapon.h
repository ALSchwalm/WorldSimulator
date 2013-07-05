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
		"Sword",
		"Bow"
	};

	const std::map<WeaponType, const Skill::skillMap> requiredWeaponSkills
	{
		{SWORD, 	{{Skill::BLACKSMITHING, 	2.5f},
					 {Skill::WOODWORKING,		0.5f}}},

		{BOW,		{{Skill::WOODWORKING, 		3.0f}}}
	};

	const std::map<WeaponType, const std::vector<std::tuple<ItemType, unsigned int, unsigned int>>> requiredWeaponItems
	{
		{SWORD,		{std::make_tuple(WEAPON, SWORD, 1)}}
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

		static const Skill::skillMap & getRequiredSkill(WeaponType t){return requiredWeaponSkills.at(t);}
		static const std::vector<std::tuple<ItemType, unsigned int, unsigned int>> & getRequiredItems(WeaponType t)
		{
			return requiredWeaponItems.at(t);
		}

		const ItemType getItemType(){return WEAPON;}
		const WeaponType getWeaponType(){return weaponType;}
	private:
		WeaponType weaponType;

	};

}

#endif

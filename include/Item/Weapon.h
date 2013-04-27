#ifndef WEAPON_H_
#define WEAPON_H_

#include "Item/BaseItem.h"
#include <memory>
#include <map>
#include <string>
#include <vector>

namespace Item
{

	class Weapon : public BaseItem
	{
	public:
		Weapon(){}
		Weapon(std::string _name) : BaseItem(_name){}
		Weapon(Individual::Individual_ptr _owner) : BaseItem(_owner) {}
		Weapon(std::string _name, Individual::Individual_ptr _owner) :
			BaseItem(_name, _owner){}

		~Weapon(){};

	private:

	};

}

#endif

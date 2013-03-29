#ifndef WEAPON_H_
#define WEAPON_H_

#include <memory>
#include <map>
#include <string>
#include <vector>

namespace Item
{

	class Weapon : public BaseItem
	{
	public:
		Weapon(std::string _name) :
			BaseItem(_name){};

		~Weapon(){};

	private:

	};

}

#endif

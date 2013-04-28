#ifndef BASEITEM_H_
#define BASEITEM_H_

#include "Owner/Owner.h"
#include "Skill/Skill.h"
#include <memory>
#include <map>
#include <string>
#include <vector>

namespace Individual
{
	class BaseIndividual;
	typedef std::shared_ptr<Individual::BaseIndividual> Individual_ptr;
}

namespace Item
{

	class BaseItem
	{
	public:

		virtual ~BaseItem(){};

		std::string getName() {return name;}
		void setAttribute(std::string s) {attributes[s] = true;}
		const Owner::Owner & getOwner() {return owner;}

		bool hasAttribute(std::string s) {return attributes.find(s) != attributes.end();}

	protected:
		BaseItem() : name("Unnamed Item"){}
		BaseItem(std::string _name) : name(_name){}
		BaseItem(Individual::Individual_ptr _owner) :
			name("Unnamed Item"),
			owner(_owner)
		{}
		BaseItem(std::string _name, Individual::Individual_ptr _owner) :
			name(_name),
			owner(_owner)
		{}
	private:
		std::string name;
		std::map<std::string, bool> attributes;
		Owner::Owner owner;

	};

	typedef std::shared_ptr<BaseItem> Item_ptr;
	typedef std::vector<Item_ptr> ItemList;
}

#endif

#ifndef BASEITEM_H_
#define BASEITEM_H_

#include <memory>
#include <map>
#include <string>
#include <vector>

namespace Item
{

	class BaseItem
	{
	public:

		virtual ~BaseItem(){};

		std::string getName() {return name;}
		void setAttribute(std::string s) {attributes[s] = true;}
		bool hasAttribute(std::string s) {return attributes.find(s) != attributes.end();}

	protected:
		BaseItem() : name("Unnamed Item"){}
		BaseItem(std::string _name) : name(_name){}
	private:


		std::string name;
		std::map<std::string, bool> attributes;

	};

	typedef std::shared_ptr<BaseItem> Item_ptr;
	typedef std::vector<Item_ptr> ItemList;
}

#endif

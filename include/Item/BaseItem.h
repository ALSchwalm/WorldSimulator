#ifndef BASEITEM_H_
#define BASEITEM_H_

#include <memory>
#include <map>
#include <string>

namespace Item
{

	class BaseItem
	{
	public:

		virtual ~BaseItem();

		std::string getName() {return name;}


	private:
		BaseItem();

		std::string name;
		std::map<std::string, bool> attributes;



	};

	typedef std::shared_ptr<BaseItem> Item_ptr;

}

#endif

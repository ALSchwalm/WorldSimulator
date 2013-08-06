#ifndef ITEMFACTORY_H_
#define ITEMFACTORY_H_

#include "Item/BaseItem.h"
#include "Utils/json/json.h"
#include <vector>
#include <utility>

namespace Item
{
	class ItemFactoryBase
	{
	public:
		virtual std::shared_ptr<BaseItem> make() const=0;
		virtual ~ItemFactoryBase(){};

		bool hasAttribute(const std::string& s) const;
		ID getID() const {return id;}

	protected:
		ItemFactoryBase(ID _id, const Json::Value itemRoot);

		ID id;
		const std::string name;
		skillVector requiredSkills;
		itemVector requiredItems;
		std::map<std::string, bool> attributes;
	};

	extern std::vector<std::unique_ptr<ItemFactoryBase>> itemFactories;

	template <ItemType i>
	class ItemFactory;

	template<>
	class ItemFactory<FOOD> : public ItemFactoryBase
	{
	public:
		ItemFactory(ID _id, const Json::Value itemRoot);
		std::shared_ptr<BaseItem> make() const override;
	};

	template<>
	class ItemFactory<CONTAINER> : public ItemFactoryBase
	{
	public:
		ItemFactory(ID _id, const Json::Value itemRoot);
		std::shared_ptr<BaseItem> make() const override;
	};

	template<>
	class ItemFactory<WEAPON> : public ItemFactoryBase
	{
	public:
		ItemFactory(ID _id, const Json::Value itemRoot);
		std::shared_ptr<BaseItem> make() const override;
	};

	template<>
	class ItemFactory<TOOL> : public ItemFactoryBase
	{
	public:
		ItemFactory(ID _id, const Json::Value itemRoot);
		std::shared_ptr<BaseItem> make() const override;
	private:
		skillVector usedSkills;
	};
}

#endif

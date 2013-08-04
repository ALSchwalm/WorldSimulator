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

	protected:
		ItemFactoryBase(const Json::Value itemRoot);

		const ID id;
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
		ItemFactory(const Json::Value itemRoot);
		std::shared_ptr<BaseItem> make() const override;
	};

	template<>
	class ItemFactory<CONTAINER> : public ItemFactoryBase
	{
	public:
		ItemFactory(const Json::Value itemRoot);
		std::shared_ptr<BaseItem> make() const override;
	};

	template<>
	class ItemFactory<WEAPON> : public ItemFactoryBase
	{
	public:
		ItemFactory(const Json::Value itemRoot);
		std::shared_ptr<BaseItem> make() const override;
	};

	template<>
	class ItemFactory<TOOL> : public ItemFactoryBase
	{
	public:
		ItemFactory(const Json::Value itemRoot);
		std::shared_ptr<BaseItem> make() const override;
	private:
		skillVector usedSkills;
	};

}

#endif

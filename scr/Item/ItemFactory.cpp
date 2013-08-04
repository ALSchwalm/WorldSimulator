
#include "Item/ItemFactory.h"

namespace Item
{
	std::vector<std::unique_ptr<ItemFactoryBase>> itemFactories;

	ItemFactoryBase::ItemFactoryBase(const Json::Value itemRoot) :
			id(itemRoot["ID"].asString())
	{
		std::vector<std::string>&& skillNames = itemRoot["RequiredSkills"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["RequiredSkills"].size(); ++i) {
			auto&& skillValue = itemRoot["RequiredSkills"][i];
			requiredSkills.emplace_back(skillNames.at(i), skillValue.asDouble());
		}

		auto itemNames = itemRoot["RequiredItems"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["RequiredItems"].size(); ++i) {
			auto&& itemValue = itemRoot["RequiredItems"][i];
			requiredItems.emplace_back(itemNames.at(i), itemValue.asUInt());
		}


	}

	ItemFactory<FOOD>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{

	}

	std::shared_ptr<BaseItem> ItemFactory<FOOD>::make() const {
		return nullptr;
	}



	ItemFactory<TOOL>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{
		auto skillNames = itemRoot["UsedSkills"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["UsedSkills"].size(); ++i) {
			auto&& skillValue = itemRoot["UsedSkills"][i];
			usedSkills.emplace_back(skillNames.at(i), skillValue.asDouble());
		}
	}

	std::shared_ptr<BaseItem> ItemFactory<TOOL>::make() const {
		return nullptr;
	}


	ItemFactory<CONTAINER>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{

	}

	std::shared_ptr<BaseItem> ItemFactory<CONTAINER>::make() const {
		return nullptr;
	}


	ItemFactory<WEAPON>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{

	}

	std::shared_ptr<BaseItem> ItemFactory<WEAPON>::make() const {
		return nullptr;
	}

}


#include "Item/ItemFactory.h"
#include "Item/Food.h"
#include "Item/Weapon.h"
#include "Item/Tool.h"
#include "Item/Container.h"

namespace Item
{
	std::vector<std::unique_ptr<ItemFactoryBase>> itemFactories;

	ItemFactoryBase::ItemFactoryBase(const Json::Value itemRoot) :
			id(itemRoot["ID"].asString())
	{
		std::vector<std::string> skillNames = itemRoot["RequiredSkills"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["RequiredSkills"].size(); ++i) {
			auto skillValue = itemRoot["RequiredSkills"][i];
			requiredSkills.emplace_back(skillNames.at(i), skillValue.asDouble());
		}

		auto itemNames = itemRoot["RequiredItems"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["RequiredItems"].size(); ++i) {
			auto itemValue = itemRoot["RequiredItems"][i];
			requiredItems.emplace_back(itemNames.at(i), itemValue.asUInt());
		}

		auto attributeNames = itemRoot["Attributes"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["Attributes"].size(); ++i) {
			auto itemValue = itemRoot["Attributes"][i];
			attributes[itemNames.at(i)] = itemValue.asBool();
		}

	}

	ItemFactory<FOOD>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{

	}

	std::shared_ptr<BaseItem> ItemFactory<FOOD>::make() const {
		return std::make_shared<Item::Food>(id);
	}



	ItemFactory<TOOL>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{
		auto skillNames = itemRoot["UsedSkills"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["UsedSkills"].size(); ++i) {
			auto skillValue = itemRoot["UsedSkills"][i];
			usedSkills.emplace_back(skillNames.at(i), skillValue.asDouble());
		}
	}

	std::shared_ptr<BaseItem> ItemFactory<TOOL>::make() const {
		return std::make_shared<Item::Tool>(id);
	}


	ItemFactory<CONTAINER>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{
	}

	std::shared_ptr<BaseItem> ItemFactory<CONTAINER>::make() const {
		return std::make_shared<Item::Container>(id);
	}


	ItemFactory<WEAPON>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{

	}

	std::shared_ptr<BaseItem> ItemFactory<WEAPON>::make() const {
		return std::make_shared<Item::Weapon>(id);
	}

}

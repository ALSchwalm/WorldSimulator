
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
		auto newFood = std::make_shared<Item::Food>(id);

		//Set default attributes for new item
		for (auto attribute : attributes){
			newFood->setAttribute(attribute.first, attribute.second);
		}

		return newFood;
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
		auto newTool = std::make_shared<Item::Tool>(id);

		//Set default attributes for new item
		for (auto attribute : attributes){
			newTool->setAttribute(attribute.first, attribute.second);
		}

		return newTool;
	}


	ItemFactory<CONTAINER>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{
	}

	std::shared_ptr<BaseItem> ItemFactory<CONTAINER>::make() const {
		auto newContainer = std::make_shared<Item::Container>(id);

		//Set default attributes for new item
		for (auto attribute : attributes){
			newContainer->setAttribute(attribute.first, attribute.second);
		}

		return newContainer;
	}


	ItemFactory<WEAPON>::ItemFactory(const Json::Value itemRoot) : ItemFactoryBase(itemRoot)
	{

	}

	std::shared_ptr<BaseItem> ItemFactory<WEAPON>::make() const {
		auto newWeapon = std::make_shared<Item::Weapon>(id);

		//Set default attributes for new item
		for (auto attribute : attributes){
			newWeapon->setAttribute(attribute.first, attribute.second);
		}

		return newWeapon;
	}

}

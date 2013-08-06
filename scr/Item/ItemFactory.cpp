
#include "Item/ItemFactory.h"
#include "Item/Food.h"
#include "Item/Weapon.h"
#include "Item/Tool.h"
#include "Item/Container.h"

namespace Item
{
	std::vector<std::unique_ptr<ItemFactoryBase>> itemFactories;

	ItemFactoryBase::ItemFactoryBase(ID _id, const Json::Value itemRoot) :
			id(_id),
			name(itemRoot["Name"].asString())
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

	bool ItemFactoryBase::hasAttribute(const std::string& s)
	{
		auto location = attributes.find(s);
		if (location != attributes.end())
		{
			return location->second;
		}
		return false;
	}


	ItemFactory<FOOD>::ItemFactory(ID _id, const Json::Value itemRoot) : ItemFactoryBase(_id, itemRoot)
	{

	}

	std::shared_ptr<BaseItem> ItemFactory<FOOD>::make() const {
		auto newFood = std::make_shared<Item::Food>(id, name, attributes);

		return newFood;
	}



	ItemFactory<TOOL>::ItemFactory(ID _id, const Json::Value itemRoot) : ItemFactoryBase(_id, itemRoot)
	{
		auto skillNames = itemRoot["UsedSkills"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["UsedSkills"].size(); ++i) {
			auto skillValue = itemRoot["UsedSkills"][i];
			usedSkills.emplace_back(skillNames.at(i), skillValue.asDouble());
		}
	}

	std::shared_ptr<BaseItem> ItemFactory<TOOL>::make() const {
		auto newTool = std::make_shared<Item::Tool>(id, name, attributes);

		return newTool;
	}


	ItemFactory<CONTAINER>::ItemFactory(ID _id, const Json::Value itemRoot) : ItemFactoryBase(_id, itemRoot)
	{
	}

	std::shared_ptr<BaseItem> ItemFactory<CONTAINER>::make() const {
		auto newContainer = std::make_shared<Item::Container>(id, name, attributes);

		return newContainer;
	}


	ItemFactory<WEAPON>::ItemFactory(ID _id, const Json::Value itemRoot) : ItemFactoryBase(_id, itemRoot)
	{

	}

	std::shared_ptr<BaseItem> ItemFactory<WEAPON>::make() const {
		auto newWeapon = std::make_shared<Item::Weapon>(id, name, attributes);

		return newWeapon;
	}

}

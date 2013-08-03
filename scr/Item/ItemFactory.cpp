
#include "Item/ItemFactory.h"

namespace Item
{
	ItemFactoryBase::ItemFactoryBase(const Json::Value itemRoot) :
			id(itemRoot["ID"].asString())
	{
		std::vector<std::string> skillNames = itemRoot["RequiredSkills"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["RequiredSkills"].size(); ++i) {
			auto skillValue = itemRoot["RequiredSkills"][i];
			auto skillPair = std::make_pair(skillNames.at(i), skillValue.asDouble());
			requiredSkills.push_back(skillPair);
		}

		auto itemNames = itemRoot["RequiredItems"].getMemberNames();
		for(unsigned int i=0; i < itemRoot["RequiredItems"].size(); ++i) {
			auto itemValue = itemRoot["RequiredItems"][i];
			auto itemPair = std::make_pair(skillNames.at(i), itemValue.asUInt());
			requiredItems.push_back(itemPair);
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

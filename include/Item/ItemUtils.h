#ifndef ITEMUTILS_H_
#define ITEMUTILS_H_

#include "Utils/json/json.h"
#include <utility>
#include <vector>

namespace Item
{
	typedef const std::string ID;
	typedef std::vector< std::pair<ID, double>> skillVector;
	typedef std::vector< std::pair<ID, unsigned int>> itemVector;

    bool AddItemFactory(ID _id, const Json::Value itemRoot);
}

#endif

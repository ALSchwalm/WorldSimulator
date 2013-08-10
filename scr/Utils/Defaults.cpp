
#include "Utils/Defaults.h"
#include "Utils/json/json.h"
#include "Item/ItemUtils.h"
#include <fstream>
#include <stdexcept>

namespace Utils
{

    bool loadItems(const Json::Value itemRoot);

    bool loadPlugins() {
        std::ifstream file;
        Json::Value root;   // will contains the root value after parsing.
        Json::Reader reader;


        //TODO also read in Plugins folder
        file.open("default.json");
        if (!file.is_open()) {
            throw(std::runtime_error("Error opening default.json"));
            return false;
        }

        bool parsingSuccessful = reader.parse( file, root );

        if ( !parsingSuccessful ) {
            throw(std::runtime_error("Error parsing default.json" +
            		reader.getFormatedErrorMessages()));
            return false;
        }

        loadItems(root["Items"]);

        return true;
    }

    bool loadItems(const Json::Value itemRoot) {

    	auto IDs = itemRoot.getMemberNames();
        for(unsigned int i = 0; i < itemRoot.size(); ++i)
        {
            if (!Item::AddItemFactory(IDs[i], itemRoot[IDs[i]]))
            {
                //TODO log error
            }
        }

        return true;
    }

}


#include "Utils/Defaults.h"
#include "Utils/Conversion.h"
#include "Item/ItemUtils.h"
#include "Profession/ProfessionFactory.h"
#include <boost/python.hpp>
#include <memory>
#include <boost/filesystem.hpp>

namespace Utils
{
    using namespace boost::python;
    using namespace boost::filesystem;

    bool loadPlugins() {

        Py_Initialize();
        setupConversions(); //TODO put this somewhere else

        object main_module((handle<>(borrowed(PyImport_AddModule("__main__")))));
        object main_namespace = main_module.attr("__dict__");

        exec("import sys, inspect; sys.path.append('.');", main_namespace);

        path p ("plugins/");
        boost::iterator_range<directory_iterator> files =
            boost::make_iterator_range(directory_iterator(p), directory_iterator());

        for(auto& file : files){
            if (is_regular_file(file)) {
                std::string name = file.path().stem().string();
                auto load = std::string("from plugins." ) + name + std::string(" import *;");
                exec(load.c_str(), main_namespace);
            }
        }

        list itemClasses = extract<list>(eval("[obj for (name, obj) "
                                              "in inspect.getmembers(sys.modules[__name__]) "
                                              "if inspect.isclass(obj) "
                                              "and issubclass(obj, BaseItem) "
                                              "and obj not in ["
                                                  "BaseItem, BaseContainer,"
                                                  "BaseWeapon, BaseFood, "
                                                  "BaseTool, "
                                              "]]", main_namespace));

        for(unsigned int i=0; i < len(itemClasses); ++i) {
            Item::AddItemFactory(itemClasses[i]);
        }

        list profClasses = extract<list>(eval("[obj for (name, obj) "
                                              "in inspect.getmembers(sys.modules[__name__]) "
                                              "if inspect.isclass(obj) "
                                              "and issubclass(obj, BaseProfession) "
                                              "and obj not in ["
                                                  "BaseProfession"
                                              "]]", main_namespace));

        for(unsigned int i=0; i < len(profClasses); ++i) {
            Profession::professionFactories.emplace_back(
                new Profession::ProfessionFactory(profClasses[i]));
        }

        return true;
    }
}

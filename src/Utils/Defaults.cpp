
#include "Utils/Defaults.h"
#include "Utils/Conversion.h"
#include "Item/ItemUtils.h"
#include <boost/python.hpp>
#include <fstream>
#include <stdexcept>

namespace Utils
{
    using namespace boost::python;

    bool loadPlugins() {
        try {
            Py_Initialize();
            setupConversions(); //TODO put this somewhere else

            object main_module((handle<>(borrowed(PyImport_AddModule("__main__")))));
            object main_namespace = main_module.attr("__dict__");

            exec("import sys, inspect; sys.path.append('.');"
                 "from plugins import *;", main_namespace);

            list classes = extract<list>(eval("[obj for (name, obj) "
                                              "in inspect.getmembers(sys.modules[__name__]) "
                                              "if inspect.isclass(obj) "
                                              "and obj != BaseItem]", main_namespace));

            for(unsigned int i=0; i < classes.length; ++i) {
                Item::AddItemFactory(classes[i]);
            }

            return true;
        }
        catch( error_already_set ) {
            PyErr_Print();
            return false;
        }
    }
}

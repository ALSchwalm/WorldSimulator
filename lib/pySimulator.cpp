#include "Item/BaseItem.h"
#include "Item/Container.h"
#include <boost/python.hpp>
#include <memory>
#include <string>

using namespace boost::python;

BOOST_PYTHON_MODULE(simulator) {
    class_<Item::BaseItem,
           boost::noncopyable,
           std::shared_ptr<Item::BaseItemPy>>("BaseItem", init<std::string>())
        .add_property("attributes",
                      &Item::BaseItem::getAttributes,
                      &Item::BaseItem::setAttributes)
        .def("getClassID", &Item::BaseItem::getClassID)
        .def("getRequiredItems", &Item::BaseItem::getRequiredItems);

    class_<Item::BaseContainer,
           boost::noncopyable,
           bases<Item::BaseItem>,
           std::shared_ptr<Item::BaseContainerPy>>("BaseContainer", init<std::string>());
}

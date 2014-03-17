#include "Item/BaseItem.h"
#include <boost/python.hpp>
#include <memory>

using namespace boost::python;

BOOST_PYTHON_MODULE(simulator) {
    class_<Item::BaseItem,
           boost::noncopyable,
           std::shared_ptr<Item::BaseItemPy>>("BaseItem", init<>())
        .add_property("attributes",
                      &Item::BaseItem::getAttributes,
                      &Item::BaseItem::setAttributes)
        .def("getID", &Item::BaseItem::getClassID)
        .def("getRequiredItems", &Item::BaseItem::getRequiredItems);
}

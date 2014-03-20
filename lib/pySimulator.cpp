#include "Item/BaseItem.h"
#include "Item/Container.h"
#include "Item/Tool.h"
#include "Item/Weapon.h"
#include "Item/Food.h"
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

    class_<Item::BaseTool,
           boost::noncopyable,
           bases<Item::BaseItem>,
           std::shared_ptr<Item::BaseToolPy>>("BaseTool", init<std::string>());

    class_<Item::BaseWeapon,
           boost::noncopyable,
           bases<Item::BaseItem>,
           std::shared_ptr<Item::BaseWeaponPy>>("BaseWeapon", init<std::string>());

    class_<Item::BaseFood,
           boost::noncopyable,
           bases<Item::BaseItem>,
           std::shared_ptr<Item::BaseFoodPy>>("BaseFood", init<std::string>());

}

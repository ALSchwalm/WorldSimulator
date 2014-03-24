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
        .add_property("requiredItems",
                      &Item::BaseItem::getRequiredItems,
                      &Item::BaseItem::setRequiredItems)
        .def("getClassID", &Item::BaseItem::getClassID);

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
           std::shared_ptr<Item::BaseWeaponPy>>("BaseWeapon", init<std::string>())
        .add_property("damageModifiers",
                      &Item::BaseWeapon::getDamageModifiers,
                      &Item::BaseWeapon::setDamageModifiers);

    enum_<Item::DamageType>("damage_type")
        .value("piercing", Item::DamageType::PIERCING)
        .value("slashing", Item::DamageType::SLASHING)
        .value("blunt", Item::DamageType::BLUNT);


    class_<Item::BaseFood,
           boost::noncopyable,
           bases<Item::BaseItem>,
           std::shared_ptr<Item::BaseFoodPy>>("BaseFood", init<std::string>());

}

#include "Item/Weapon.h"
#include "Profession/ProfessionUtils.h"
#include <boost/test/unit_test.hpp>
#include "Utils/Utils.h"
BOOST_AUTO_TEST_SUITE(Profession)

BOOST_AUTO_TEST_CASE(RelatedItems)
{
    auto newItems = Profession::getRandomProfession()->getRelatedItems();
    std::vector<Item::Item_ptr> items;

    for(unsigned int s=0; s < boost::python::len(newItems); ++s) {
        items.push_back(extract<Item::Item_ptr>(newItems[s]()));
    }

    BOOST_CHECK(!items.empty());
}

BOOST_AUTO_TEST_SUITE_END()

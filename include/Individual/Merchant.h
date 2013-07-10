/*
 * Person.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef MERCHANT_H_
#define MERCHANT_H_

#include "Event/Event.h"
#include "Event/BaseEvent.h"
#include "Individual/BaseProfession.h"
#include <string>
#include <memory>

namespace Item
{
    class BaseItem;
    typedef std::shared_ptr<BaseItem> Item_ptr;
}

namespace Location
{
    class BaseLocation;
    typedef std::shared_ptr<BaseLocation> Location_ptr;
}

namespace Profession
{
    class Merchant : virtual public BaseProfession
    {
    public:

        virtual std::vector<Item::Item_ptr> getItemsForSale() { return itemsForSale;}

        ProfessionType getProfessionType() override {return ProfessionType::PROFESSION_ERROR;}
        virtual void addInitialItems(std::vector<Item::Item_ptr>&){};

    protected:
        Merchant(){}

        Merchant(const Merchant&) = delete;
        Merchant& operator=(const Merchant&) = delete;

        ~Merchant(){}

    private:
        std::vector<Item::Item_ptr> itemsForSale;

    };
}
#endif

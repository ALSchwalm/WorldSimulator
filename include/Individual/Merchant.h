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
#include "Individual/BaseIndividual.h"
#include <string>
#include <memory>

namespace Item
{
	class BaseItem;
	typedef std::shared_ptr<BaseItem> Item_ptr;
}

namespace Individual
{
	class Merchant : public BaseIndividual
	{
	public:

		virtual std::vector<Item::Item_ptr> getItemsForSale() { return itemsForSale;}
		virtual void addInitialItems(std::vector<Item::Item_ptr> &)=0;

		IndividualType getIndividualType() override {return IndividualType::MERCHANT;}

	protected:
		Merchant(std::string name, bool);
		Merchant(std::string name, Location_ptr location, bool);

	private:
		std::vector<Item::Item_ptr> itemsForSale;

	};
}
#endif

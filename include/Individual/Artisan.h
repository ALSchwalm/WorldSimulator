#ifndef ARTISAN_H
#define ARTISAN_H_

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
    class Artisan : virtual public BaseIndividual
    {
    public:
        virtual Item::Item_ptr createItem(){return NULL;}
        virtual IndividualType getIndividualType() override {return IndividualType::INDIVIDUAL_ERROR;}

        virtual void addInitialItems(std::vector<Item::Item_ptr> &){};
    protected:
        Artisan(std::string name, bool);
        Artisan(std::string name, Location_ptr location, bool);

        Artisan(const Artisan&) = delete;
        Artisan& operator=(const Artisan&) = delete;

    private:


    };
}
#endif

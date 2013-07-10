#ifndef ARTISAN_H
#define ARTISAN_H_

#include "Event/Event.h"
#include "Event/BaseEvent.h"
#include "Profession/BaseProfession.h"
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
    class Artisan : virtual public BaseProfession
    {
    public:
        virtual Item::Item_ptr createItem(){return NULL;}
        virtual ProfessionType getProfessionType() override {return ProfessionType::PROFESSION_ERROR;}

    protected:
        Artisan(){}

        Artisan(const Artisan&) = delete;
        Artisan& operator=(const Artisan&) = delete;

    private:


    };
}
#endif

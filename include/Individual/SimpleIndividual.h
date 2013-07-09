#ifndef SIMPLEINDIVIDUAL_H_
#define SIMPLEINDIVIDUAL_H_

#include "Individual/BaseProfession.h"
#include "Individual/Artisan.h"
#include "Individual/Merchant.h"

#include "Item/Food.h"
#include "Skill/Skill.h"

namespace Profession
{
    class Baker : public Artisan, public Merchant
    {
    public:
        Baker()
        {
            //setSkill(Skill::BAKING, 5.0f);
            //setSkill(Skill::COOKING, 5.0f);
        }

        ProfessionType getProfessionType() override {return ProfessionType::BAKER;}

        void addInitialItems(std::vector<Item::Item_ptr>& items)
        {
            items.push_back(std::make_shared<Item::Food<Item::BREAD> >());
        };

    };





}
#endif

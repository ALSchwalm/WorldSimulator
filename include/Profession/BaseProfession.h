#ifndef BASEPROFESSION_H_
#define BASEPROFESSION_H_

#include "Profession/Profession.h"
#include "Skill/Skill.h"
#include <memory>

namespace Profession
{

    class BaseProfession
    {
    public:
        virtual ProfessionType getProfessionType()=0;
        virtual void addInitialItems(std::vector<Item::Item_ptr> &)=0;
        const float getSkillLevel(Skill::skills s) noexcept;

        virtual ~BaseProfession(){}
    protected:
        BaseProfession(){}

        bool setSkill(Skill::skills s, const float f);
        Skill::skillMap skillMap;

    };

    typedef std::shared_ptr<BaseProfession> Profession_ptr;

}

#endif

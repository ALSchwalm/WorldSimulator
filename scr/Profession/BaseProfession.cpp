#include "Profession/BaseProfession.h"
#include <exception>

namespace Profession
{
    const float BaseProfession::getSkillLevel(Skill::skills s) noexcept
    {
        try {
            return skillMap.at(s);
        }

        catch (std::exception& e){
            return 0.0f;
        }
    }

    bool BaseProfession::setSkill(Skill::skills s, const float f)
    {
        skillMap[s] = f;
        return true;
    }

}

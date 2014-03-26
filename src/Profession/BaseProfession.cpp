#include "Profession/BaseProfession.h"
#include <exception>

namespace Profession
{
    float BaseProfession::getSkillLevel(Skill::SkillType s)
    {
        try {
            return extract<float>(skillModifiers[s]);
        }
        catch( error_already_set ) {
            return 0.0f;
        }
    }

    bool BaseProfession::setSkill(Skill::SkillType s, const float f)
    {
        skillModifiers[s] = f;
        return true;
    }

}

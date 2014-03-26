#ifndef SKILL_H_
#define SKILL_H_

#include <memory>
#include <map>
#include <string>
#include <vector>


namespace Skill
{
    enum class SkillType
    {
        MARKSMANSHIP,
        BLACKSMITHING,
        WOODWORKING,
        BAKING,
        COOKING,
        FARMING,

        NUM_OF_SKILLS
    };

    typedef std::map<Skill::SkillType, float> skillMap;

}

#endif

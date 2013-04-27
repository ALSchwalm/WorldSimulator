#ifndef SKILL_H_
#define SKILL_H_

#include <memory>
#include <map>
#include <string>
#include <vector>


namespace Skill
{
	enum skills
	{
		MARKSMANSHIP,
		BLACKSMITH,
		BAKERY,

		NUM_OF_SKILLS
	};

	typedef std::map<Skill::skills, float> skillMap;

}

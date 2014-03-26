#ifndef BASEPROFESSION_H_
#define BASEPROFESSION_H_

#include "Skill/Skill.h"
#include "Item/BaseItem.h"
#include <boost/python.hpp>
#include <memory>

namespace Profession
{
    using namespace boost::python;

    class BaseProfession
    {
    public:
        float getSkillLevel(Skill::SkillType s);

        dict getSkillModifiers() {return skillModifiers;}
        void setSkillModifiers(dict modifiers) {skillModifiers = modifiers;}

        const std::string& getName() const {return name;}

        virtual ~BaseProfession(){}

    protected:
        BaseProfession(std::string _name) : name(_name) {}
        BaseProfession() : BaseProfession("Unnamed Profession") {}

        bool setSkill(Skill::SkillType s, const float f);
        dict skillModifiers;
        const std::string name;
    };

    typedef std::shared_ptr<BaseProfession> Profession_ptr;


    class BaseProfessionPy : public virtual BaseProfession
    {
    public:
        BaseProfessionPy(PyObject *p) : self(p) {}
        BaseProfessionPy(PyObject *p, std::string _name) :
            BaseProfession(_name), self(p) {}

    protected:
        PyObject *self;

    };
}

#endif

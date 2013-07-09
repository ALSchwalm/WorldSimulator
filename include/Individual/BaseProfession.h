#ifndef BASEPROFESSION_H_
#define BASEPROFESSION_H_

#include <memory>

namespace Profession
{
    enum ProfessionType
    {
        BAKER,

        //insert before this
        NUM_OF_INDIVIDUALS,
        INDIVIDUAL_ERROR
    };


    class BaseProfession
    {
    public:
        virtual ProfessionType getProfessionType()=0;

        virtual ~BaseProfession(){}
    private:

    };

    typedef std::shared_ptr<BaseProfession> Profession_ptr;

}

#endif

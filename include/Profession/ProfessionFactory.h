#ifndef PROFESSIONFACTORY_H_
#define PROFESSIONFACTORY_H_

#include "Profession/BaseProfession.h"
#include <boost/python.hpp>
#include <vector>

namespace Profession
{
    class ProfessionFactory
    {
    public:
        template<typename... Args>
        std::shared_ptr<BaseProfession> make() const {
            return extract<std::shared_ptr<BaseProfession>>(pyClass());
        }

        ProfessionFactory(object _pyClass) : pyClass(_pyClass) {}

    private:
        object pyClass;
    };

    extern std::vector<std::unique_ptr<ProfessionFactory>> professionFactories;
}

#endif

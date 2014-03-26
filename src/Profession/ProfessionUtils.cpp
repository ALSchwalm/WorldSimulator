
#include "Profession/ProfessionFactory.h"
#include "Profession/ProfessionUtils.h"
#include "Utils/Utils.h"

namespace Profession
{
    Profession_ptr getRandomProfession() {
        return professionFactories[Utils::uniform(0, professionFactories.size())]->make();
    }
}

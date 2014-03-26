#include "Profession/ProfessionFactory.h"
#include "Utils/Utils.h"

namespace Profession
{
    std::vector<std::unique_ptr<ProfessionFactory>> professionFactories;

    Profession_ptr getRandomProfession() {
        return professionFactories[Utils::uniform(0, professionFactories.size())]->make();
    }
}

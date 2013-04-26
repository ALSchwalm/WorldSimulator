#include "Individual/Artisan.h"

namespace Individual
{

Artisan::Artisan(std::string s, bool _isMale=true) : BaseIndividual(s, _isMale)
{
}

Artisan::Artisan(std::string s, Location_ptr location, bool _isMale=true) : BaseIndividual(s, location, _isMale)
{
}

}

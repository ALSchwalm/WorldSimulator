
#include "Individual/Merchant.h"

namespace Individual
{

Merchant::Merchant(std::string s, bool _isMale=true) : BaseIndividual(s, _isMale)
{
}

Merchant::Merchant(std::string s, Location_ptr location, bool _isMale=true) : BaseIndividual(s, location, _isMale)
{
}

}

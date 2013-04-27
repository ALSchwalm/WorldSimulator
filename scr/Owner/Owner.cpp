
#include "Owner/Owner.h"

namespace Owner
{

	Owner::Owner(std::shared_ptr<Individual::BaseIndividual> o)
	{
		owner.push_back(o);
	}

	Owner::Owner(const std::vector<Individual::Individual_ptr> & os)
	{
		owner = os;
	}

	bool operator==(Owner lhs, Individual::Individual_ptr rhs)
	{
		if (lhs.owner.size() != 1)
		{
			return false;
		}
		else
		{
			return lhs.owner[0] == rhs;
		}
	}

	bool operator!=(Owner lhs, Individual::Individual_ptr rhs)
	{
		return !(lhs == rhs);
	}

	bool operator==(Owner & lhs, std::vector<Individual::Individual_ptr> & rhs)
	{
		return lhs == rhs;
	}

	bool operator!=(Owner & lhs, std::vector<Individual::Individual_ptr> & rhs)
	{
		return !(lhs == rhs);
	}
}


#include "Owner/Owner.h"
#include "Actor/Individual.h"

namespace Owner
{

    Owner::Owner(std::shared_ptr<Actor::Individual> o)
    {
        owner.push_back(o);
    }

    Owner::Owner(const std::vector<Actor::Individual_ptr> & os) :
        owner(os)
    {
    }

    bool Owner::operator==(const Owner& o) const {
        return owner == o.owner;
    }

    bool operator==(const Owner& lhs, const Actor::Individual_ptr& rhs)
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

    bool operator==(const Owner& lhs, const std::vector<Actor::Individual_ptr>& rhs)
    {
        return lhs == rhs;
    }

    std::string Owner::getName() const
    {
        if (owner.size() == 1 && owner[0] != nullptr)
        {
            return owner[0]->getName();
        }
        else if (owner.size() > 1)
        {
            return "Group";
        }
        else
        {
            return "None";
        }
        return "";
    }

}

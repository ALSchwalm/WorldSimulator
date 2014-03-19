#ifndef OWNER_H_
#define OWNER_H_


#include <vector>
#include <memory>
#include <string>
#include <boost/operators.hpp>

namespace Actor
{
    class Individual;
    typedef std::shared_ptr<Individual> Individual_ptr;
}


namespace Owner
{

    class Owner : boost::equality_comparable<Owner>,
                  boost::equality_comparable<Owner, Actor::Individual_ptr>,
                  boost::equality_comparable<Owner, std::vector<Actor::Individual_ptr>>
    {
    public:
        Owner(){}
        Owner(std::shared_ptr<Actor::Individual>);
        Owner(const std::vector<Actor::Individual_ptr>&);

        bool operator==(const Owner& o) const;
        friend bool operator==(const Owner& o, const Actor::Individual_ptr&);
        friend bool operator==(const Owner& o, const std::vector<Actor::Individual_ptr>&);

        std::string getName() const;

    private:
        std::vector<Actor::Individual_ptr> owner;

    };

}

#endif

#ifndef OWNER_H_
#define OWNER_H_


#include <vector>
#include <memory>
#include <string>

namespace Actor
{
    class Individual;
    typedef std::shared_ptr<Individual> Individual_ptr;
}


namespace Owner
{

    class Owner
    {
    public:
        Owner(){}
        Owner(std::shared_ptr<Actor::Individual>);
        Owner(const std::vector<Actor::Individual_ptr>&);

        friend bool operator==(Owner o, Actor::Individual_ptr);
        friend bool operator!=(Owner o, Actor::Individual_ptr);
        friend bool operator==(const Owner& o, std::vector<Actor::Individual_ptr>&);
        friend bool operator!=(const Owner& o, std::vector<Actor::Individual_ptr>&);

        std::string getName() const;

    private:
        std::vector<Actor::Individual_ptr> owner;

    };

}

#endif

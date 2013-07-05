#ifndef OWNER_H_
#define OWNER_H_


#include <vector>
#include <memory>

namespace Individual
{
    class BaseIndividual;
    typedef std::shared_ptr<Individual::BaseIndividual> Individual_ptr;
}


namespace Owner
{

    class Owner
    {
    public:
        Owner(){}
        Owner(std::shared_ptr<Individual::BaseIndividual>);
        Owner(const std::vector<Individual::Individual_ptr>&);

        friend bool operator==(Owner o, Individual::Individual_ptr);
        friend bool operator!=(Owner o, Individual::Individual_ptr);
        friend bool operator==(const Owner& o, std::vector<Individual::Individual_ptr>&);
        friend bool operator!=(const Owner& o, std::vector<Individual::Individual_ptr>&);

    private:
        std::vector<Individual::Individual_ptr> owner;

    };

}

#endif

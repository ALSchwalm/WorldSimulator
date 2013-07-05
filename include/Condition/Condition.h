#ifndef CONDITION_H_
#define CONDITION_H_

#include <memory>
#include <utility>
#include <functional>
#include <vector>

namespace Condition
{

    class ConditionList
    {

    public:

        ConditionList(){};

        template<typename T, typename U>
        void addCondition( bool(*f)(T, U), T t, U u);


        bool isSatisfied();

    private:
        std::vector< std::function<bool()> > conditions;

    };


    template<typename T, typename U>
    void ConditionList::addCondition( bool (*f)(T, U), T t, U u)
    {
        auto func = [=]{ return f(t, u); };
        conditions.push_back(func);
    }

    bool ConditionList::isSatisfied()
    {
        for (auto c : conditions)
        {
            if (!c())
            {
                return false;
            }
        }
        return true;
    }


    template<typename T, typename U>
    bool HAS_ATTRIBUTE(T t, U u)
    {
        if (t->hasAttribute(u))
            return true;
        return false;
    }

}
#endif

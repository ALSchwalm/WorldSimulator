#ifndef NAME_H_
#define NAME_H_

#include <string>
#include <vector>

namespace Utils
{
    class Title
    {

    };

    //TODO find a better place for this
    enum PositiveTitles
    {
        GREAT,
        TERRIBLE,
        FEROCIOUS,
        FEEBLE,

        NUM_OF_POSITIVE_TITLES
    };

    class Name
    {
    public:
        Name(std::string _first){};
        Name(std::string _first, std::string _last){};

        void addTitle(std::string suffix){};

        std::string getNameWithModifiers(){};


    private:
        std::vector<Title> titles;
    };
}
#endif

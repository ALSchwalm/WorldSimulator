#ifndef RANGEVIEW_H_
#define RANGEVIEW_H_

#if _WIN32
    #include "Utils/curses.h"
#endif

#include "Profession/BaseProfession.h"
#include "Location/BaseLocation.h"
#include "Interface/View.h"
#include "Utils/Utils.h"

namespace Interface
{
    //type T represent the view subject type, while U represent the type of information
    //to show. So RangeView<Indivdiual, Location> shows location information about an
    //individual.
    template<typename T, typename U>
    class RangeView : public View<T>
    {
    public:
        RangeView(T t) : View<T>(t, "Range View"){};

        bool expandArg(CLI::Token&) override;
        void refreshView();
    };
}
#endif

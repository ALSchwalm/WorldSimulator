#ifndef RANGEVIEW_H_
#define RANGEVIEW_H_

#if _WIN32
#include "Utils/curses.h"
#endif

#include "Location/BaseLocation.h"
#include "Interface/View.h"

namespace Interface
{
    template<typename T>
    class RangeView : public View<T>
    {
    public:
        RangeView(T t) :
            View<T>(t, "List View"){}
        void refreshView();
    };

    template<>
    void RangeView<Location::Location_ptr>::refreshView()
    {
        unsigned int i=3;
        for (auto location : viewSubject->getLocations())
        {
            mvwprintw(this->viewWin, i, 4, location->getName().c_str());
            ++i;
        }
        wrefresh(this->viewWin);
    }
}
#endif


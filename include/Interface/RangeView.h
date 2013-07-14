#ifndef RANGEVIEW_H_
#define RANGEVIEW_H_

#if _WIN32
#include "Utils/curses.h"
#endif

#include "Profession/BaseProfession.h"
#include "Location/BaseLocation.h"
#include "Interface/View.h"

namespace Interface
{
    template<typename T, typename U>
    class RangeView : public View<T>
    {
    public:
        RangeView(T t);


        void refreshView();
    };

    template<>
    RangeView<Location::Location_ptr, Location::Location_ptr>::RangeView(Location::Location_ptr t) :
        View<Location::Location_ptr>(t, "Location List View"){}

    template<>
    RangeView<Location::Location_ptr, Item::Item_ptr>::RangeView(Location::Location_ptr t) :
        View<Location::Location_ptr>(t, "Item List View"){}

    template<>
    RangeView<Location::Location_ptr, Actor::Individual_ptr>::RangeView(Location::Location_ptr t) :
        View<Location::Location_ptr>(t, "Individual List View"){}


    template<>
    void RangeView<Location::Location_ptr, Location::Location_ptr>::refreshView()
    {
        mvwprintw(this->nameWin, 2, 4, "Name:");
        mvwprintw(this->dataWin, 2, 4, "Type:");

        unsigned int i=4;
        for (auto location : viewSubject->getLocations())
        {
            mvwprintw(this->nameWin, i, 4, location->getName().c_str());
            mvwprintw(this->dataWin, i, 4, Location::toString(location->getLocationType()).c_str());
            ++i;
        }
        wrefresh(this->nameWin);
        wrefresh(this->dataWin);
    }

    template<>
    void RangeView<Location::Location_ptr, Item::Item_ptr>::refreshView()
    {
        mvwprintw(this->nameWin, 2, 4, "Name:");
        mvwprintw(this->dataWin, 2, 4, "Owner:");

        unsigned int i=4;
        for (auto item : viewSubject->getItems())
        {
            mvwprintw(this->nameWin, i, 4, item->getName().c_str());
            mvwprintw(this->dataWin, i, 4, item->getOwner().getName().c_str());

            ++i;
        }
        wrefresh(this->nameWin);
        wrefresh(this->dataWin);
    }

    template<>
    void RangeView<Location::Location_ptr, Actor::Individual_ptr>::refreshView()
    {
        mvwprintw(this->nameWin, 2, 4, "Name:");
        mvwprintw(this->dataWin, 2, 4, "Profession:");

        unsigned int i=4;
        for (auto individual : viewSubject->getIndividuals())
        {
            mvwprintw(this->nameWin, i, 4, individual->getName().c_str());
            mvwprintw(this->dataWin, i, 4, Profession::toString(individual->getProfession()->getProfessionType()).c_str());
            ++i;
        }
        wrefresh(this->nameWin);
        wrefresh(this->dataWin);
    }


}
#endif


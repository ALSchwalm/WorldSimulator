#ifndef GENERALVIEW_H_
#define GENERALVIEW_H_

#if _WIN32
# include "Utils/curses.h"
#elif __linux__
# include <ncurses.h>
#endif

#include "Interface/View.h"
#include "Location/Location.h"
#include "Actor/Individual.h"
#include <memory>
#include <boost/lexical_cast.hpp>

namespace Interface
{
    /*
    * GeneralView's 'refreshView' member is partially
    * specialized for every type used, to account for
    * the necessary differences in the important information
    * between types.
    */
    template<typename T>
    class GeneralView : public View<T>
    {
    public:
        GeneralView(T);
        void refreshView() override;
    };


    template<typename T>
    GeneralView<T>::GeneralView(T _viewSubject) :
        View<T>(_viewSubject, "Overview"){}

    template<>
    inline void GeneralView<Location::Location_ptr>::refreshView()
    {
        std::string val;

        mvwprintw(this->nameWin, 2, 4, "Statistic:");
        mvwprintw(this->nameWin, 4, 4, "Adjacent locations");
        mvwprintw(this->nameWin, 5, 4, "Individuals");
        mvwprintw(this->nameWin, 6, 4, "Items");

        mvwprintw(this->dataWin, 2, 4, "Value:");

        val = boost::lexical_cast<std::string>(viewSubject->getLocations().size());
        mvwprintw(this->dataWin, 4, 4, val.c_str());

        val = boost::lexical_cast<std::string>(viewSubject->getIndividuals().size());
        mvwprintw(this->dataWin, 5, 4, val.c_str());

        val = boost::lexical_cast<std::string>(viewSubject->getItems().size());
        mvwprintw(this->dataWin, 6, 4, val.c_str());

        wrefresh(this->nameWin);
        wrefresh(this->dataWin);
    }

    template<>
    inline void GeneralView<Actor::Individual_ptr>::refreshView()
    {
        std::string val;

        mvwprintw(this->nameWin, 2, 4, "Statistic:");
        mvwprintw(this->nameWin, 4, 4, "Current Location");
        mvwprintw(this->nameWin, 5, 4, "Inventory size");
        mvwprintw(this->nameWin, 6, 4, "Age");

        mvwprintw(this->dataWin, 2, 4, "Value:");

        mvwprintw(this->dataWin, 4, 4, viewSubject->getCurrentLocation()->getName().c_str());

        val = boost::lexical_cast<std::string>(viewSubject->getItems().size());
        mvwprintw(this->dataWin, 5, 4, val.c_str());

        val = boost::lexical_cast<std::string>(viewSubject->getAge());
        mvwprintw(this->dataWin, 6, 4, val.c_str());

        wrefresh(this->nameWin);
        wrefresh(this->dataWin);
    }


}

#endif

#include "Interface/RangeView.h"
#include <boost/lexical_cast.hpp>

namespace Interface {
    template<>
    bool RangeView<Location::Location_ptr, Actor::Individual_ptr>::expandArg(CLI::Token& token)
    {
        if (int index = atoi(token.value.c_str()))
        {
            if (index > 0 && static_cast<unsigned int>(index-1) < viewSubject->getIndividuals().size()) {
                token.value = viewSubject->getIndividuals()[index-1]->getName();
                return true;
            }
        }
        return false;
    }

    template<>
    bool RangeView<Location::Location_ptr, Location::Location_ptr>::expandArg(CLI::Token& token)
    {
        if (int index = atoi(token.value.c_str()))
        {
            if (index > 0 && static_cast<unsigned int>(index-1) < viewSubject->getLocations().size()) {
                auto iter = viewSubject->getLocations().begin();
                std::advance(iter, index-1);        //Locations are of type unordered_set to use advance
                token.value = (*iter)->getName();
                return true;
            }
        }
        return false;
    }

    template<>
    bool RangeView<Location::Location_ptr, Item::Item_ptr>::expandArg(CLI::Token& token)
    {
        if (int index = atoi(token.value.c_str()))
        {
            if (index > 0 && static_cast<unsigned int>(index-1) < viewSubject->getItems().size()) {
                token.value = viewSubject->getItems()[index-1]->getName();
                return true;
            }
        }
        return false;
    }

    template<>
    void RangeView<Location::Location_ptr, Location::Location_ptr>::refreshView()
    {
        mvwprintw(this->nameWin, 2, 4, "Name:");
        mvwprintw(this->dataWin, 2, 4, "Type:");

        unsigned int i=4;
        for (auto location : viewSubject->getLocations())
        {
            mvwprintw(this->nameWin, i, 1, boost::lexical_cast<std::string>(i-3).c_str());
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
            mvwprintw(this->nameWin, i, 1, boost::lexical_cast<std::string>(i-3).c_str());
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
            mvwprintw(this->nameWin, i, 1, boost::lexical_cast<std::string>(i-3).c_str());
            mvwprintw(this->nameWin, i, 4, individual->getName().c_str());
            mvwprintw(this->dataWin, i, 4, individual->getProfession()->getName().c_str());
            ++i;
        }
        wrefresh(this->nameWin);
        wrefresh(this->dataWin);
    }
}

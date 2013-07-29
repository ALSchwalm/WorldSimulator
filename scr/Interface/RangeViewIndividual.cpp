#include "Interface/RangeView.h"


namespace Interface {
    template<>
    bool RangeView<Actor::Individual_ptr, Item::Item_ptr>::expandArg(CLI::Token& token)
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
    void RangeView<Actor::Individual_ptr, Item::Item_ptr>::refreshView()
    {
        mvwprintw(this->nameWin, 2, 4, "Name:");
        mvwprintw(this->dataWin, 2, 4, "Owner:");

        unsigned int i=4;
        for (auto item : viewSubject->getItems())
        {
            mvwprintw(this->nameWin, i, 2, Utils::numberToString(i-3).c_str());
            mvwprintw(this->nameWin, i, 4, item->getName().c_str());
            mvwprintw(this->dataWin, i, 4, item->getOwner().getName().c_str());

            ++i;
        }
        wrefresh(this->nameWin);
        wrefresh(this->dataWin);
    }
}

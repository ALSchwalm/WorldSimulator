#ifndef HELPVIEW_H_
#define HELPVIEW_H_

#if _WIN32
# include "Utils/curses.h"
#elif __linux__
# include <ncurses.h>
#endif

#include <vector>
#include "Interface/View.h"
#include "Interface/CLI/Commands.h"

namespace Interface
{
    /*
    * HelpView is a special case of view. It is not derived from View<T> or baseView,
    * and it is not held in Interface::displayView. Instead, it has its own
    * Interface::helpView variable. When a helpView is destroyed, it will
    * either call a redraw of the displayView, or, if it is being replaced
    * with another help view, it will do nothing.
    */

    class HelpView
    {
    public:
        HelpView(std::vector<CLI::Command>);
        ~HelpView();
        void redrawView(){};
        void refreshView();
        WINDOW* getTitleWin() {return titleWin;}
        WINDOW* getNameWin() {return nameWin;}
        WINDOW* getDataWin() {return dataWin;}
    private:
        WINDOW* titleWin;
        WINDOW* nameWin;
        WINDOW* dataWin;
        std::vector<CLI::Command> commands;
    };
}
#endif

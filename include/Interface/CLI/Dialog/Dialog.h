#ifndef DIALOG_H_
#define DIALOG_H_

#if _WIN32
# include "Utils/curses.h"
#elif __linux__
# include <ncurses.h>
#endif

#include <memory>

namespace Interface
{
    namespace CLI
    {
        class Dialog
        {
        public:
            virtual ~Dialog()
            {
                //delwin(dialogWin);
            }
            virtual void handleInput()=0;

        protected:
            Dialog(WINDOW* win) :
                dialogWin(win)
            {
                box(dialogWin, 0, 0);
                refresh();
            }
            WINDOW* dialogWin;

        };

        typedef std::shared_ptr<Dialog> Dialog_ptr;

    }
}

#endif

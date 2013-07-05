#ifndef DIALOGOK_H_
#define DIALOGOK_H_

#if _WIN32
# include "Utils/curses.h"
#elif __linux__
# include <ncurses.h>
#endif

#include "Interface/CLI/Dialog/Dialog.h"
#include <string>

namespace Interface
{
    namespace CLI
    {
        class DialogOK : public Dialog
        {
        public:
            DialogOK(std::string);
            void handleInput();
        };
    }
}

#endif

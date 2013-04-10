#ifndef DIALOG_H_
#define DIALOG_H_

#include "Utils/curses.h"
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
			Dialog(WINDOW * win) :
				dialogWin(win)
			{
				box(dialogWin, 0, 0);
				refresh();
			}
			WINDOW * dialogWin;

		};

		typedef std::shared_ptr<Dialog> Dialog_ptr;

	}
}

#endif

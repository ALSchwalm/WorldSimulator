#ifndef VIEW_H_
#define VIEW_H_

#include <memory>
#include "Interface/Interface.h"
#include "Utils/curses.h"
#include "Utils/panel.h"

namespace Interface
{

	template<typename T>
	class View
	{
	public:
		virtual void refreshView()=0;

		virtual ~View()
		{
			delwin(viewWin);
		}
	protected:
		View(T _viewSubject);
		T viewSubject;
		WINDOW * viewWin;
	};


	template<typename T>
	View<T>::View(T _viewSubject) :
		viewSubject(_viewSubject)
	{
		viewWin = subwin(mainwin, LINES-3, COLS, 3, 0);
		box(viewWin, 0, 0);
		refresh();
	}

}
#endif

#ifndef VIEW_H_
#define VIEW_H_

#include <memory>
#include "Utils/curses.h"
#include "Utils/panel.h"

namespace Interface
{
	void initialize();
	extern WINDOW * mainwin;

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
		viewWin = subwin(mainwin, LINES, COLS, 0, 0);
	}

}
#endif

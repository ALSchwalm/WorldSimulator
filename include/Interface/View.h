#ifndef VIEW_H_
#define VIEW_H_

#include <memory>
#include <iostream> //TODO remove this
#include "Interface/Interface.h"
#include "Utils/curses.h"
#include "Utils/panel.h"

namespace Interface
{
	//This class wraps View, so a shared_ptr<BaseView> can be used
	class BaseView
	{
	public:
		virtual void refreshView()=0;
		virtual ~BaseView(){}
		BaseView(){} //This should never be used;

	};
	typedef std::shared_ptr<BaseView> View_ptr;


	template<typename T>
	class View : public BaseView
	{
	public:
		virtual void refreshView()=0;

		virtual ~View()
		{
			//FIXME delwin(viewWin); should be called here but
			//this crashes when exiting. viewWin has a non
			//null value at this point, so this is possibly
			//a bug with pdcurses. For now we leak memory.
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
		this->viewWin = subwin(mainwin, LINES-3, COLS, 3, 0);
		box(this->viewWin, 0, 0);
		refresh();
	}

}
#endif

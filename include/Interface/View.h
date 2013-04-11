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
		virtual void redrawView()=0;
		virtual ~BaseView(){}
		BaseView(){} //This should only be used by shared_ptr

	};
	typedef std::shared_ptr<BaseView> View_ptr;


	template<typename T>
	class View : public BaseView
	{
	public:
		virtual void refreshView()=0;
		void redrawView();

		virtual ~View()
		{
			//FIXME delwin(viewWin); should be called here but
			//this crashes when exiting. viewWin has a non
			//null value at this point, so this is possibly
			//a bug with pdcurses. For now we leak memory.
		}
	protected:
		View(T _viewSubject, std::string _viewType);
		std::string viewType;
		T viewSubject;
		WINDOW * viewWin;
	};


	template<typename T>
	View<T>::View(T _viewSubject, std::string _viewType) :
		viewType(_viewType),
		viewSubject(_viewSubject)
	{
		this->viewWin = subwin(mainwin, LINES-3, COLS, 3, 0);
		this->redrawView();
	}

	template<typename T>
	void View<T>::redrawView()
	{
		wclear(viewWin);
		box(this->viewWin, 0, 0);
		std::string status = CLI::contextAsString(currentContext) + "(" + viewSubject->getName() + "):" + viewType;
		mvwprintw(this->viewWin, 0, 2, status.c_str());

		refresh();
	}



}
#endif

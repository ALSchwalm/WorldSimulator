#ifndef EVENTVIEW_H_
#define EVENTVIEW_H_

#if _WIN32
# include "Utils/curses.h"
#elif __linux__
# include <ncurses.h>
#endif
#include <memory>
#include "Interface/View.h"

namespace Interface
{
	template<typename T>
	class EventView : public View<T>
	{
	public:
		EventView(T _viewSubject);

		void refreshView();

	};


	template<typename T>
	EventView<T>::EventView(T _viewSubject) :
		View<T>(_viewSubject, "Event History")
	{

	};

	template<typename T>
	void EventView<T>::refreshView()
	{
		unsigned int counter = 2;
		for( auto item : this->viewSubject->getHistory())
		{
			mvwprintw(this->viewWin, counter, 4, "EventInfo");
			++counter;
		}
		wrefresh(this->viewWin);
	};


}
#endif

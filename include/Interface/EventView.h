#ifndef EVENTVIEW_H_
#define EVENTVIEW_H_

#include <memory>
#include "Interface/View.h"
#include "Utils/curses.h"
#include "Utils/panel.h"

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
		View<T>(_viewSubject, _viewSubject->getName())
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

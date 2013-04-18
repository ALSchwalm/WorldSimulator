#ifndef GENERALVIEW_H_
#define GENERALVIEW_H_

#include "Interface/View.h"
#include "Utils/curses.h"
#include "Location/Location.h"
#include <memory>
#include <sstream>

namespace Interface
{

	/*
	 * GeneralView's 'refreshView' member is partially
	 * specialized for every type used, to account for
	 * the necessary differences in the important information
	 * between types.
	 */
	template<typename T>
	class GeneralView : public View<T>
	{
	public:
		GeneralView(T);
		void refreshView();
	};


	template<typename T>
	GeneralView<T>::GeneralView(T _viewSubject) :
		View<T>(_viewSubject, "Overview"){}

	template<>
	inline void GeneralView<Location::Location_ptr>::refreshView()
	{
		//TODO this should be changed to std::to_string() once MingW fixes this function
		std::stringstream ss;
		ss << viewSubject->getLocations().size();

		mvwprintw(this->viewWin, 2, 4, std::string("Adjacent locations\t\t" + ss.str()).c_str());
		wrefresh(this->viewWin);
	}

}

#endif

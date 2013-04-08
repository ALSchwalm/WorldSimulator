#ifndef INTERFACE_H_
#define INTERFACE_H_


#include "Utils/curses.h"
#include <memory>

namespace Interface
{
	class BaseView;

	void initialize();
	void refreshView();
	extern WINDOW * mainwin;
	extern std::shared_ptr<BaseView> displayView;
}
#endif

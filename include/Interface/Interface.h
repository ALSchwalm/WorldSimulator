#ifndef INTERFACE_H_
#define INTERFACE_H_


#include "Utils/curses.h"
#include "Interface/CLI/Context.h"
#include <memory>

namespace Interface
{
	class BaseView;

	void initialize();
	void refreshView();

	extern WINDOW * mainwin;
	extern std::shared_ptr<BaseView> displayView;
	extern std::shared_ptr<BaseView> helpView;
	extern CLI::Context currentContext;
}
#endif

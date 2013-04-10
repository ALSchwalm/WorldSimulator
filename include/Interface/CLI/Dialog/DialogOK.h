#ifndef DIALOGOK_H_
#define DIALOGOK_H_

#include "Utils/curses.h"
#include "Interface/CLI/Dialog/Dialog.h"
#include <string>

namespace Interface
{
	namespace CLI
	{
		class DialogOK : public Dialog
		{
		public:
			DialogOK(std::string);
			void handleInput();
		};
	}
}

#endif

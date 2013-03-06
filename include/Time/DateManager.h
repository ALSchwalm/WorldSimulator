#ifndef DATEMANAGER_H_
#define DATEMANAGER_H_

#include "Time/Date.h"

namespace Time
{
	class DateManager {
	public:
		static DateManager & getInstance();

	private:
		DateManager(){};

	};
}




#endif

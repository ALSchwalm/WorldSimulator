#ifndef DATEMANAGER_H_
#define DATEMANAGER_H_

#include "Time/Date.h"

namespace Time
{
	class DateManager {
	public:
		static DateManager & getInstance();

		void nextDay() {++now;}

		Date now;

	private:
		DateManager();

		const unsigned int DAYS_PER_SECOND = 5;

	};


	//shorthand for Time::DateManager::getInstance().now
	inline Date & now() {return DateManager::getInstance().now;}
}


#endif

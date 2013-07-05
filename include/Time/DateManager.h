#ifndef DATEMANAGER_H_
#define DATEMANAGER_H_

#include "Time/Date.h"

namespace Time
{
	class DateManager {
	public:
		static DateManager& getInstance();

		void nextMinute() {++now;}

		Date now;

	private:
		DateManager();

	};

	//shorthand for Time::DateManager::getInstance().now
	inline const Date& now() {return DateManager::getInstance().now;}
}


#endif

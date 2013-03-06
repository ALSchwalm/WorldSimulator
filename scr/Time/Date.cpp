/*
 * Date.cpp
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#include "Time/Date.h"

namespace Time {

	Date::Date(unsigned int _year, Month _month, Day _day) :
		year(_year),
		month(_month),
		day(_day)
	{

	}


	bool Date::operator ==(Date rhs)
	{
		if (rhs.day == this->day 	 &&
			rhs.month == this->month &&
			rhs.year == this->year)
			return true;
		return false;
	}

} /* namespace Time */

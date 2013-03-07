/*
 * Date.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>

namespace Time {

	struct Year{
		unsigned int value;
	};

	enum Month
	{
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December,

		NUM_OF_MONTHS
	};

	enum Day
	{
		Sunday,
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,

		NUM_OF_DAYS
	};

	class Date {

	public:
		Date(unsigned int year, Month month, Day day);

		unsigned int getYear() {return year;}
		Month getMonth() {return month;}
		Day getDay() {return day;}

		bool operator ==(Date);
		Date & operator++();

		friend std::ostream& operator<<(std::ostream &out, Date &d);

	private:

		static const unsigned int DAYS_PER_MONTH = 30;

		unsigned int year;
		Month month;
		Day day;
		unsigned int dayValue;
	};

} /* namespace Time */
#endif /* DATE_H_ */

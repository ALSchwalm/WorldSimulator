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
	friend Date operator+(Date, int);

	public:
		Date(unsigned int year, Month month, Day day, unsigned short hour=0, unsigned short minute=0);

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
		unsigned short hour;
		unsigned short minute;
		unsigned int dayValue; //as in, the 18th day of the month
	};


} /* namespace Time */
#endif /* DATE_H_ */

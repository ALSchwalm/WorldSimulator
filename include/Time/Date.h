/*
 * Date.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#ifndef DATE_H_
#define DATE_H_

namespace Time {

	struct Year{
		unsigned int value;
	};

	enum Month
	{
		January,
		February
	};

	enum Day
	{
		Sunday,
		Monday
	};

	class Date {

	public:
		Date(unsigned int year, Month month, Day day);

		unsigned int getYear() {return year;}
		Month getMonth() {return month;}
		Day getDay() {return day;}

		bool operator ==(Date);

	private:
		unsigned int year;
		Month month;
		Day day;
	};

} /* namespace Time */
#endif /* DATE_H_ */

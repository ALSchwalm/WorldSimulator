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

	struct Month{
			unsigned int value;
	};

	struct Day{
			unsigned int value;
	};


	class Date {

	public:
		Date(Year year, Month month, Day day);

		Year getYear() {return year;}
		Month getMonth() {return month;}
		Day getDay() {return day;}

	private:
		Year year;
		Month month;
		Day day;
	};

} /* namespace Time */
#endif /* DATE_H_ */

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
		day(_day),
		dayValue(0)
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

	Date & Date::operator++()
	{
		dayValue++;
		unsigned int temp_month = static_cast<Month> (month);

		if ( dayValue+1 > DAYS_PER_MONTH )
		{
			dayValue = 0;
			temp_month++;

			if ( temp_month+1 > NUM_OF_MONTHS)
			{
				temp_month = 0;
				year++;
			}
		}

		dayValue %= DAYS_PER_MONTH;

		day = static_cast <Day> (dayValue % NUM_OF_DAYS);
		month = static_cast <Month> (temp_month % NUM_OF_MONTHS);

		return *this;
	}

	std::ostream& operator<<(std::ostream &out, Date &d)
	{
		std::string out_day;
		std::string out_month;

		switch (d.day)
		{
		case Sunday:
			out_day = "Sunday";
			break;
		case Monday:
			out_day = "Monday";
			break;
		case Tuesday:
			out_day = "Tuesday";
			break;
		case Wednesday:
			out_day = "Wednesday";
			break;
		case Thursday:
			out_day = "Thursday";
			break;
		case Friday:
			out_day = "Friday";
			break;
		case Saturday:
			out_day = "Saturday";
			break;
		default:
			out_day = "Undefined Day";
			break;
		}

		switch (d.month)
		{
		case January:
			out_month = "January";
			break;
		case February:
			out_month = "February";
			break;
		case March:
			out_month = "March";
			break;
		case April:
			out_month = "April";
			break;
		case May:
			out_month = "May";
			break;
		case June:
			out_month = "June";
			break;
		case July:
			out_month = "July";
			break;
		case August:
			out_month = "August";
			break;
		case September:
			out_month = "September";
			break;
		case October:
			out_month = "October";
			break;
		case November:
			out_month = "November";
			break;
		case December:
			out_month = "December";
			break;
		default:
			out_month = "Undefined Month";
			break;
		}

		out << out_day << " the " << d.dayValue+1 << " of " << out_month << ", " << d.year;

		return out;
	}

} /* namespace Time */

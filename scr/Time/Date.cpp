/*
 * Date.cpp
 *
 *  Created on: Mar 4, 2013
 *      Author: Adam
 */

#include "Time/Date.h"
#include <sstream>

namespace Time {

    Date operator+(Date d, int x)
    {
        Date temp(d);
        for (int i=0; i < x; ++i)
            ++temp;
        return temp;
    }

    Date::Date(unsigned int _year, Month _month, Day _day, unsigned short _hour, unsigned short _minute) :
        year(_year),
        month(_month),
        day(_day),
        hour(_hour),
        minute(_minute),
        dayValue(0)
    {
    }


    bool Date::operator==(const Date& rhs) const
    {
        if (rhs.day == this->day 	 &&
            rhs.month == this->month &&
            rhs.year == this->year   &&
            rhs.hour == this->hour   &&
            rhs.minute == this->minute)
            return true;
        return false;
    }

    bool Date::operator!=(const Date& rhs) const
    {
        return !((*this) == rhs);
    }

    Date & Date::operator++()
    {
        ++minute;

        if (minute >= 60 )
        {
            ++hour;
            minute %= 60;
            if (hour >= 24)
            {
                ++dayValue;
                hour %= 24;
            }
            else
            {
                return *this;
            }
        }
        else
        {
            return *this;
        }


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

    std::string Date::getDateAsString(bool concise) const
    {
        std::string out_day;
        std::string out_month;

        switch (day)
        {
        case Day::Sunday:
            out_day = "Sunday";
            break;
        case Day::Monday:
            out_day = "Monday";
            break;
        case Day::Tuesday:
            out_day = "Tuesday";
            break;
        case Day::Wednesday:
            out_day = "Wednesday";
            break;
        case Day::Thursday:
            out_day = "Thursday";
            break;
        case Day::Friday:
            out_day = "Friday";
            break;
        case Day::Saturday:
            out_day = "Saturday";
            break;
        default:
            out_day = "Undefined Day";
            break;
        }

        switch (month)
        {
        case Month::January:
            out_month = "January";
            break;
        case Month::February:
            out_month = "February";
            break;
        case Month::March:
            out_month = "March";
            break;
        case Month::April:
            out_month = "April";
            break;
        case Month::May:
            out_month = "May";
            break;
        case Month::June:
            out_month = "June";
            break;
        case Month::July:
            out_month = "July";
            break;
        case Month::August:
            out_month = "August";
            break;
        case Month::September:
            out_month = "September";
            break;
        case Month::October:
            out_month = "October";
            break;
        case Month::November:
            out_month = "November";
            break;
        case Month::December:
            out_month = "December";
            break;
        default:
            out_month = "Undefined Month";
            break;
        }

        std::ostringstream ss;

        if (!concise)
            ss << out_day << " the " << dayValue+1 << " of " << out_month << ", " << year << " " << hour << ":" << minute;
        else
            ss << dayValue+1 << "-" << out_month << "-" << year;

        return ss.str();

    }

    std::ostream& operator<<(std::ostream &out, Date &d) {
        return out << d.getDateAsString();
    }


} /* namespace Time */

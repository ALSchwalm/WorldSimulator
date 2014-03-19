#ifndef DATE_H_
#define DATE_H_

#include <boost/operators.hpp>
#include <ctime>
#include <cstring>

namespace Time
{
    struct Date : boost::less_than_comparable<Date>,
                  boost::equality_comparable<Date> {

        Date(const std::tm& tm) {
            this->tm = tm;
        }

        Date() {
            memset(&tm, sizeof(tm), 0);
            tm.tm_year = -1899;
            tm.tm_mday = 1;
        }

        int setYear(int year)     {tm.tm_year = year; mktime(&tm);  return tm.tm_year;}
        int setMonth(int month)   {tm.tm_mon = month; mktime(&tm);  return tm.tm_mon;}
        int setDay(int day)       {tm.tm_mday = day; mktime(&tm);   return tm.tm_mday;}
        int setHour(int hour)     {tm.tm_hour = hour; mktime(&tm);  return tm.tm_hour;}
        int setMinute(int minute) {tm.tm_min = minute; mktime(&tm); return tm.tm_min;}
        int setSecond(int second) {tm.tm_sec = second; mktime(&tm); return tm.tm_sec;}

        int getYear()   const {return tm.tm_year;}
        int getMonth()  const {return tm.tm_mon;}
        int getDay()    const {return tm.tm_mday;}
        int getHour()   const {return tm.tm_hour;}
        int getMinute() const {return tm.tm_min;}
        int getSecond() const {return tm.tm_sec;}

        bool operator<(const Date& d) const {
            auto left = tm;
            auto right = d.tm;
            return std::mktime(&left) < std::mktime(&right);
        }

        bool operator==(const Date& d) const {
            return getYear() == d.getYear() &&
                getMonth() == d.getMonth() &&
                getDay() == d.getDay() &&
                getHour() == d.getHour() &&
                getMinute() == d.getMinute() &&
                getSecond() == d.getSecond();
        }

        Date operator=(const tm& tm) {
            return this->tm = tm;
        }

        std::string toString() const {
            char mbstr[100];
            std::strftime(mbstr, 100, "%B %e %Y %R", &tm);
            return std::string(mbstr);
        }

        static_assert(sizeof(std::time_t) >= 8, "Insufficient time_t size");
        std::tm tm;
    };
}

#endif

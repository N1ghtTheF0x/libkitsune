#include <N1ghtTheF0x/LibKitsune/Date.hpp>

const char* monthString[] = {
    "Invalid",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        Date::Date()
        {
            _time = std::chrono::system_clock::now();
        }
        Date::Date(std::chrono::system_clock::time_point init): _time(init)
        {
            auto time = std::chrono::system_clock::to_time_t(_time);
            tm t = *localtime(&time);
            
        }
        Date::operator std::chrono::system_clock::time_point() const
        {
            return _time;
        }
        Date::operator time_t() const
        {
            return std::chrono::system_clock::to_time_t(_time);
        }
        Date::operator tm() const
        {
            time_t time = operator time_t();
            return *localtime(&time);
        }
        Date::operator String() const
        {
            return toString();
        }
        s32 Date::year() const
        {
            return operator tm().tm_year + 1900;
        }
        s32 Date::month() const
        {
            return operator tm().tm_mon + 1;
        }
        s32 Date::day() const
        {
            return operator tm().tm_mday;
        }
        s32 Date::monthDay() const
        {
            return operator tm().tm_mday;
        }
        s32 Date::weekDay() const
        {
            return operator tm().tm_wday;
        }
        s32 Date::yearDay() const
        {
            return operator tm().tm_yday;
        }
        s32 Date::hour() const
        {
            return operator tm().tm_hour;
        }
        s32 Date::minute() const
        {
            return operator tm().tm_min;
        }
        s32 Date::second() const
        {
            return operator tm().tm_sec;
        }
        bool Date::summerTime() const
        {
            return operator tm().tm_isdst > 0;
        }
        String Date::toTimeString() const
        {
            auto _hour = hour();
            auto _minute = minute();
            auto _second = second();

            String string;

            if(_hour < 10)
                string.append('0');
            string.append(_hour).append(':');
            if(_minute < 10)
                string.append('0');
            string.append(_minute).append(':');
            if(_second < 10)
                string.append('0');
            string.append(_second);

            return string;
        }
        String Date::toDateString() const
        {
            auto _day = day();
            auto _month = monthString[month()];
            auto _year = year();

            String string;

            string
            .append(_day)
            .append(' ')
            .append(_month)
            .append(' ')
            .append(_year);

            return string;
        }
        String Date::toString() const
        {
            String string;

            string
            .append(toDateString())
            .append(' ')
            .append(toTimeString());

            return string;
        }
    }
}
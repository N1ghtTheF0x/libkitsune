#ifndef __N1GHTTHEF0X_LIBKITSUNE_DATE_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_DATE_HPP

#include <chrono>

#include "Numbers.hpp"
#include "String.hpp"

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        class Date
        {
        private:
            std::chrono::system_clock::time_point _time;
        public:
            Date();
            Date(std::chrono::system_clock::time_point init);

            operator std::chrono::system_clock::time_point() const;
            operator time_t() const;
            operator tm() const;
            operator String() const;

            s32 year() const;
            s32 month() const;
            s32 day() const;

            s32 monthDay() const;
            s32 weekDay() const;
            s32 yearDay() const;

            s32 hour() const;
            s32 minute() const;
            s32 second() const;

            bool summerTime() const;

            String toTimeString() const;
            String toDateString() const;
            String toString() const;
        };
    }
}

#endif
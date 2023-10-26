#ifndef __N1GHTTHEF0X_LIBKITSUNE_STRING_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_STRING_HPP

#include <cstring>
#include <string>
#include <sstream>

#include "Numbers.hpp"

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        class String
        {
        private:
            char* _pointer;
            u64 _length;
        public:
            String();
            String(const char letter);
            String(const char* cstr);
            String(const bool state);
            String(const std::string string);
            String(const std::stringstream &ss);
            #define STRING_NUMBER(type) String(const type number);
            STRING_NUMBER(s8)
            STRING_NUMBER(u8)
            STRING_NUMBER(s16)
            STRING_NUMBER(u16)
            STRING_NUMBER(s32)
            STRING_NUMBER(u32)
            STRING_NUMBER(s64)
            STRING_NUMBER(u64)
            STRING_NUMBER(float)
            STRING_NUMBER(double)
            #undef STRING_NUMBER
            ~String();

            operator const char*() const;
            operator const std::string() const;

            bool operator ==(const String &string) const;
            bool operator !=(const String &string) const;
            bool operator <(const String &string) const;
            bool operator >(const String &string) const;
            bool operator <=(const String &string) const;
            bool operator >=(const String &string) const;

            String &operator =(const String &string);
            String operator +(const String &string);
            String &operator +=(const String &string);

            u64 length() const;
            char charAt(u64 index) const;
            String &append(const String &string);
            bool empty() const;
            String add(const String &string);
            String substring(u64 start);
            String substring(u64 start,u64 end);
            bool startsWith(const String &string);
            bool endsWith(const String &string);
            bool includes(const String &string);
        private:
            u64 _memory_length() const;
            void _resize(u64 size);
        };
    }
}

#endif
#ifndef __N1GHTTHEF0X_LIBKITSUNE_STRING_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_STRING_HPP

#include "Memory.hpp"

#ifdef HAS_STRING
    #include <string>
#endif
#ifdef HAS_SSTREAM
#   include <sstream>
#endif

#include "Numbers.hpp"

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        class String
        {
        private:
            /**
             * @brief Memory address to characters (with `'\0'`)
             * 
             */
            char* _pointer;
            /**
             * @brief Contains the character count (without `'\0'`)
             * 
             */
            Size _length;
        public:
            static String toBase(u64 number,u64 base);
            /**
             * @brief Create a new empty string
             * 
             */
            String();
            /**
             * @brief Create a new string with just one character
             * 
             * @param letter A character
             */
            String(const char letter);
            /**
             * @brief Create a new string from a `const char*` pointer
             * 
             * @param cstr 
             */
            String(const char* cstr);
            /**
             * @brief Create a new string that is `"true"` or `"false"` depending on `state`
             * 
             * @param state A boolean value which turns into `"true"` or `"false"`
             */
            String(const bool state);
#ifdef HAS_STRING
            /**
             * @brief Create a new string from a `std::string` instance
             * 
             * @param string A `std::string` instance
             */
            String(const std::string string);
#endif
#ifdef HAS_SSTREAM
            /**
             * @brief Create a new string from a `std::stringstream` reference
             * 
             * @param ss A `std::stringstream` reference
             */
            String(const std::stringstream &ss);
#endif
            String(const String &string);
            #define STRING_NUMBER(type) String(const type number);
            STRING_NUMBER(u8)
            STRING_NUMBER(u16)
            STRING_NUMBER(u32)
            STRING_NUMBER(u64)
            #undef STRING_NUMBER
            ~String();

            operator const char*() const;
#ifdef HAS_STRING
            operator const std::string() const;
#endif

            bool operator ==(const String &string) const;
            bool operator !=(const String &string) const;
            bool operator <(const String &string) const;
            bool operator >(const String &string) const;
            bool operator <=(const String &string) const;
            bool operator >=(const String &string) const;

            String &operator =(const String &string);
            String operator +(const String &string);
            String &operator +=(const String &string);

            /**
             * @brief Returns the length of the string (without `'\0'`)
             * 
             * @return The length of the string (without `'\0'`)
             */
            Size length() const;
            /**
             * @brief Get a character from `index`
             * 
             * @param index A position which is inside the string's content
             * @return The character at `index`
             * @throw The character is not inside the string - `OutOfBoundsError`
             */
            char charAt(Size index) const;
            /**
             * @brief Add a string at the end of this string (`"abc" + "def" = "abcdef"`)
             * 
             * @param string The string to add at the end
             */
            String &append(const String &string);
            /**
             * @brief Checks if the string is empty. 
             * This does not include the `'\0'` character
             */
            bool empty() const;
            /**
             * @brief Add a string at the end of this copied string (`"abc" + "def" = "abcdef"`)
             * 
             * @param string The string to add at the end
             */
            String add(const String &string);
            /**
             * @brief Extracts a new string from `start` to `String::length()`
             * 
             * @param start The start to cut off
             * @return A new string that has this string's content from `start` to `String::length()`
             */
            String substring(Size start);
            /**
             * @brief Extracts a new string from `start` to `end`
             * 
             * @param start The start to cut off
             * @param end The end to finish the string
             * @return A new string that has this string's content from `start` to `end`
             */
            String substring(Size start,Size end);
            /**
             * @brief Check if the string starts with `string`
             * 
             * @param string The string to check with
             */
            bool startsWith(const String &string);
            /**
             * @brief Check if the string ends with `string`
             * 
             * @param string The string to check with
             */
            bool endsWith(const String &string);
            /**
             * @brief Check if `string` is somewhere inside this string instance
             * 
             * @param string The string to check with
             */
            bool includes(const String &string);
            /**
             * @brief Adds `string` in front of this string instance
             * 
             * @param string The string to add to the front
             */
            String &prefix(const String &string);
            /**
             * @brief Reverses the content of the string
             * 
             * @return The copied string but backwards 
             */
            String reverse();
        private:
            /**
             * @brief The length of this string with the null terminator
             * 
             * @return Size 
             */
            Size _memory_length() const;
            /**
             * @brief Fully resizes this string
             * 
             * @param size The new memory size in bytes
             */
            void _resize(Size size);
            /**
             * @brief Fully resizes this string but from front
             * 
             * @param size The new memory size in bytes
             */
            void _resizeFront(Size size);
        };
    }
}

#endif
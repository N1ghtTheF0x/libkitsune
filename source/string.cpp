#include <N1ghtTheF0x/LibKitsune/String.hpp>

#include <exception>

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        String::String()
        {
            _length = 0;
            _pointer = new char[_memory_length()];
            _pointer[_length] = '\0';
        }
        String::String(const bool state): String(state ? "true" : "false")
        {

        }
        String::String(const char letter)
        {
            _length = 1;
            _pointer = new char[_memory_length()];
            _pointer[0] = letter;
            _pointer[_length] = '\0';
        }
        String::String(const char* cstr)
        {
            _length = strlen(cstr);
            _pointer = new char[_memory_length()];
            memcpy(_pointer,cstr,_length);
            _pointer[_length] = '\0';
        }
        String::String(const std::string string): String(string.c_str())
        {
            
        }
        String::String(const std::stringstream &stream): String(stream.str())
        {

        }
        #define STRING_NUMBER(type) String::String(type number): String(std::to_string(number)) {  }
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
        String::~String()
        {
            delete _pointer;
        }
        String::operator const char *() const
        {
            return _pointer;
        }
        String::operator const std::string() const
        {
            return _pointer;
        }
        bool String::operator==(const String &string) const
        {
            if(_length != string._length) return false;
            for(u64 index = 0;index < _length;index++)
                if(charAt(index) != string.charAt(index))
                    return false;
            return true;
        }
        bool String::operator!=(const String &string) const
        {
            return !operator==(string);
        }
        bool String::operator<(const String &string) const
        {
            return _length < string._length;
        }
        bool String::operator>(const String &string) const
        {
            return _length > string._length;
        }
        bool String::operator<=(const String &string) const
        {
            return _length <= string._length;
        }
        bool String::operator>=(const String &string) const
        {
            return _length >= string._length;
        }
        String &String::operator=(const String &string)
        {
            _length = string._length;
            delete _pointer;
            _pointer = new char[_memory_length()];
            memcpy(_pointer,string._pointer,string._length);
            _pointer[_length] = '\0';
            return *this;
        }
        String String::operator+(const String &string)
        {
            return add(string);
        }
        String &String::operator+=(const String &string)
        {
            return append(string);
        }
        u64 String::length() const
        {
            return _length;
        }
        bool String::empty() const
        {
            return _length == 0;
        }
        u64 String::_memory_length() const
        {
            return _length + 1;
        }
        char String::charAt(u64 index) const
        {
            if(index < 0 || index > _length)
                throw std::exception("Char out of bounds in string");
            return _pointer[index];
        }
        void String::_resize(u64 size)
        {
            char* current = new char[_memory_length()];
            u64 currentLength = _length;
            memcpy(current,_pointer,_length);
            delete _pointer;

            _length = size;
            _pointer = new char[_memory_length()];
            memcpy(_pointer,current,currentLength < _length ? currentLength : _length);
            _pointer[_length] = '\0';
        }
        String &String::append(const String &string)
        {
            u64 currentLength = _length;
            _resize(_length + string._length);
            memcpy(_pointer + currentLength,string._pointer,string._length);
            return *this;
        }
        String String::add(const String &string)
        {
            String newString(_pointer);
            return newString.append(string);
        }
        String String::substring(u64 start)
        {
            return substring(start,_length);
        }
        String String::substring(u64 start,u64 end)
        {
            u64 length = end - start;
            char* temp = new char[length+1];
            temp[length] = '\0';

            memcpy(temp,_pointer + start,length);

            String string(temp);
            delete string;
            return string;
        }
        bool String::startsWith(const String &string)
        {
            for(u64 index = 0;index < string._length;index++)
            {
                char thisChar = charAt(index);
                char otherChar = string.charAt(index);
                if(thisChar != otherChar)
                    return false;
            }
            return true;
        }
        bool String::endsWith(const String &string)
        {
            for(u64 index = 0;index < string._length;index++)
            {
                char thisChar = charAt(_length - 1 - index);
                char otherChar = string.charAt(string._length - 1 - index);
                if(thisChar != otherChar)
                    return false;
            }
            return true;
        }
        bool String::includes(const String &string)
        {
            u64 check = 0;
            for(u64 index = 0;index < _length;index++)
            {
                if(check == string._length) return true;
                check = charAt(index) == string.charAt(check) ? check + 1 : 0;
            }
            return false;
        }
    }
}
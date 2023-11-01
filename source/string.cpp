#include <N1ghtTheF0x/LibKitsune/String.hpp>
#include <N1ghtTheF0x/LibKitsune/Error.hpp>

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        Size strlen(const char* string)
        {
            Size length = 0;

            while(string[length])
                length++;

            return length;
        }
        String::String()
        {
            _length = 0;
            _pointer = (char*)Memory::create(1);
            _pointer[_length] = '\0';
        }
        String::String(const bool state): String(state ? "true" : "false")
        {

        }
        String::String(const char letter)
        {
            _length = 1;
            _pointer = (char*)Memory::create(_memory_length());
            _pointer[0] = letter;
            _pointer[_length] = '\0';
        }
        String::String(const char* cstr)
        {
            _length = strlen(cstr);
            _pointer = (char*)Memory::create(_memory_length());
            Memory::copy(cstr,_pointer,_length);
            _pointer[_length] = '\0';
        }
        String::String(const std::string string): String(string.c_str())
        {
            
        }
        String::String(const std::stringstream &stream): String(stream.str())
        {

        }
        #define STRING_UINT(type) \
        String::String(const type value) \
        { \
            _length = 0; \
            _pointer = (char*)Memory::create(1); \
            _pointer[_length] = '\0'; \
            type number = value; \
            while(number > 0) \
            { \
                char letter = 0x30 + number % 10; \
                prefix(letter); \
                number = number / 10; \
            } \
        }
        STRING_UINT(u8)
        STRING_UINT(u16)
        STRING_UINT(u32)
        STRING_UINT(u64)
        #undef STRING_INT
        String::String(const String &string)
        {
            _length = string._length;
            _pointer = (char*)Memory::create(_length+1);
            _pointer[_length] = '\0';
            Memory::copy(string._pointer,_pointer,_length);
        }
        String::~String()
        {
            if(_pointer != nullptr)
                Memory::erase(_pointer,_memory_length());
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
            for(Size index = 0;index < _length;index++)
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
            Memory::erase(_pointer,_memory_length());
            _length = string._length;
            _pointer = (char*)Memory::create(_memory_length());
            Memory::copy(string._pointer,_pointer,string._length);
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
        Size String::length() const
        {
            return _length;
        }
        bool String::empty() const
        {
            return _length == 0;
        }
        Size String::_memory_length() const
        {
            return _length + 1;
        }
        char String::charAt(Size index) const
        {
            if(index < 0 || index > _length)
                throw OutOfBoundsError(index,_length);
            return _pointer[index];
        }
        void String::_resize(Size size)
        {
            char* temp = (char*)Memory::create(size);
            Memory::move(_pointer,temp,_length);
            _length = size-1;
            _pointer = temp;
            _pointer[_length] = '\0';
        }
        void String::_resizeFront(Size size)
        {
            char* temp = (char*)Memory::create(size);
            Memory::move(_pointer,temp + _length,_length);
            _length = size-1;
            _pointer = temp;
            _pointer[_length] = '\0';
        }
        String &String::append(const String &string)
        {
            if(_length == 0)
            {
                this->operator=(string);
                return *this;
            }
            Size length = _length + string._length;
            char* temp = (char*)Memory::create(length+1);
            temp[length] = '\0';
            Memory::copy(_pointer,temp,_length);
            Memory::copy(string._pointer,temp + _length,string._length);
            Memory::erase(_pointer,_length);
            _length = length;
            _pointer = temp;
            return *this;
        }
        String &String::prefix(const String &string)
        {
            if(_length == 0)
            {
                this->operator=(string);
                return *this;
            }
            Size length = _length + string._length;
            char* temp = (char*)Memory::create(length+1);
            temp[length] = '\0';
            Memory::copy(_pointer,temp + string._length,_length);
            Memory::copy(string._pointer,temp,string._length);
            Memory::erase(_pointer,_length);
            _length = length;
            _pointer = temp;
            return *this;
        }
        String String::reverse()
        {
            String string;
            Size n = _length;
            while(n--)
                string.append(charAt(n));
            return string;
        }
        String String::add(const String &string)
        {
            String newString(_pointer);
            return newString.append(string);
        }
        String String::substring(Size start)
        {
            return substring(start,_length);
        }
        String String::substring(Size start,Size end)
        {
            Size length = end - start;
            char* temp = (char*)Memory::create(length+1);
            temp[length] = '\0';

            Memory::copy(_pointer + start,temp,length);

            return temp;
        }
        bool String::startsWith(const String &string)
        {
            for(Size index = 0;index < string._length;index++)
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
            for(Size index = 0;index < string._length;index++)
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
            Size check = 0;
            for(Size index = 0;index < _length;index++)
            {
                if(check == string._length) return true;
                check = charAt(index) == string.charAt(check) ? check + 1 : 0;
            }
            return false;
        }
    }
}
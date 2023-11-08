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
        String String::toBase(u64 number,u64 base)
        {
            char num_t[] = {
                '0','1','2','3','4','5','6','7','8','9',
                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                'a','b','c','d','e','f','h','j','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
            };
            #define SIZE Memory::size(num_t)
            if(base < 2)
                throw Error("Error","Base is lower than 2");
            if(base >= Memory::size(num_t))
                throw Error("Error",String("Base is higher/equals ").append(SIZE));
            String string;
            u64 v = number;
            while(v != 0)
            {
                u64 result = (v/base)|0;
                string.prefix(num_t[v % base]);
                v = result;
            }
            return string;
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

#ifdef HAS_STRING
        String::String(const std::string string): String(string.c_str())
        {
            
        }
#endif
#ifdef HAS_SSTREAM
        String::String(const std::stringstream &stream): String(stream.str())
        {

        }
#endif
        #define STRING_UINT(type) \
        String::String(const type value): String() \
        { \
            type number = value; \
            while(number > 0) \
            { \
                char letter = '0' + number % 10; \
                prefix(letter); \
                number = number / 10; \
            } \
        }
        STRING_UINT(u8)
        STRING_UINT(u16)
        STRING_UINT(u32)
        STRING_UINT(u64)
        #undef STRING_UINT
        #define STRING_SINT(type) \
        String::String(const type value): String() \
        { \
            type n = value; \
            if(value < 0) \
                n = -n; \
            prefix((u64)n); \
            if(value < 0) prefix('-'); \
        }
        STRING_SINT(s8)
        STRING_SINT(s16)
        STRING_SINT(s32)
        STRING_SINT(s64)
        #undef STRING_SINT
        #define STRING_FRAC(type) \
        String::String(const type value): String() \
        { \
            s64 int_value = value; \
            prefix(int_value); \
            type fraction = value - int_value; \
            if(fraction != 0) \
            { \
                append("."); \
                if(fraction < 0) fraction = -fraction;  /* TODO: somehow parse fraction into string*/ \
            } \
        }
        STRING_FRAC(float)
        STRING_FRAC(double)
        STRING_FRAC(ldouble)
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
        const char String::operator[](Size index) const
        {
            return _pointer[index];
        }
        char &String::operator[](Size index)
        {
            return _pointer[index];
        }
        String &String::set(Size index,const char character)
        {
            if(index < 0 || index >= _length)
                throw OutOfBoundsError(index,_length);
            _pointer[index] = character;
            return *this;
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
            if(index < 0 || index >= _length)
                throw OutOfBoundsError(index,_length);
            return _pointer[index];
        }
        Size String::indexOf(String value,Size offset) const
        {
            for(Size index = offset;index < _length;index++)
            {
                if(Memory::same(_pointer + index,value._pointer,value._length))
                    return index;
            }
            return -1;
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
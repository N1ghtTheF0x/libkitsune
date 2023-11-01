#ifndef __N1GHTTHEF0X_LIBKITSUNE_ERROR_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_ERROR_HPP

#include "String.hpp"

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        class String;
        class Error
        {
        protected:
            const String _name;
            const String _message;
        public:
            Error();
            Error(const String name);
            Error(const String name,const String message);
            operator const String();
            operator const char*();
        };
        class OutOfBoundsError : public Error
        {
        private:
            const Size _index;
            const Size _length;
        public:
            OutOfBoundsError(const Size index,const Size length);
            operator const String();
        };
    }
}

#endif
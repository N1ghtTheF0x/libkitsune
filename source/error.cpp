#include <N1ghtTheF0x/LibKitsune/Error.hpp>

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        Error::Error(): Error("Error")
        {

        }
        Error::Error(const String name): Error(name,"Unknown Cause")
        {

        }
        Error::Error(const String name,const String message): _name(name), _message(message)
        {

        }
        Error::operator const String()
        {
            String string;

            string
            .append(_name)
            .append(": ")
            .append(_message);

            return string;
        }
        Error::operator const char *()
        {
            return operator const String();
        }
        OutOfBoundsError::OutOfBoundsError(const Size index,const Size length): Error("OutOfBoundsError"), _index(index), _length(length)
        {

        }
        OutOfBoundsError::operator const String()
        {
            String string;

            string
            .append(_name)
            .append(": Index was ")
            .append(_index);
            if(_index < 0)
                return string
                .append(" but it was below 0");
            return string
            .append(" but it was bigger than ")
            .append(_length);
        }
    }
}
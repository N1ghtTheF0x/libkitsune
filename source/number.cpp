#include <N1ghtTheF0x/LibKitsune/Numbers.hpp>

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        namespace IEEE754
        {
            bool sign(float value)
            {
                u32 intV = (u32)value;
                return false;
            }
            bool sign(double value)
            {
                return false;
            }
        }
        namespace Numbers
        {
            u64 char2number(char letter)
            {
                switch(letter)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        return letter - '0';
                    case 'A':
                    case 'a':
                        return 10;
                    case 'B':
                    case 'b':
                        return 11;
                    case 'C':
                    case 'c':
                        return 12;
                    case 'D':
                    case 'd':
                        return 13;
                    case 'E':
                    case 'e':
                        return 14;
                    case 'F':
                    case 'f':
                        return 15;
                    default: 
                        return letter;
                }
            }
        }
    }
}
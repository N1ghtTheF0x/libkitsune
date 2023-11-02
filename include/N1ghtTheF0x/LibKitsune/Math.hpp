#ifndef __N1GHTTHEF0X_LIBKITSUNE_MATH_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_MATH_HPP

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        namespace Math
        {
            template<typename Type>
            Type power(Type a,Type b)
            {
                Type value = 1;
                for(Size index = 0;index < b;index++)
                    value *= a;
                return value;
            }
            template<typename Type>
            Type max(Type a,Type b)
            {
                return b < a ? b : a;
            }
            template<typename Type>
            Type min(Type a,Type b)
            {
                return b < a ? a : b;
            }
            float squareRoot(float number)
            {
                long i;
                float x2, y;
                const float threehalfs = 1.5f;

                x2 = number * 0.5f;
                y = number;
                i = *(long*)&y;
                i = 0x5f3759df - (i >> 1);
                y = *(float*)&i;
                y = y * (threehalfs - (x2 * y * y));
                return y;
            }
        }
    }
}

#include "Math/Vector.hpp"

#endif
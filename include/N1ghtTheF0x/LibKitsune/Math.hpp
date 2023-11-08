#ifndef __N1GHTTHEF0X_LIBKITSUNE_MATH_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_MATH_HPP

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        namespace Math
        {
            static const double Euler = 2.718281828459045235;
            static const double Pi = 3.141592653589793;
            template<typename Type>
            Type round(float number)
            {
                return number < 0.5 ? (Type)number : (Type)number + 1;
            }
            template<typename Type>
            Type round(double number)
            {
                return number < 0.5 ? (Type)number : (Type)number + 1;
            }
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
            double squareRoot(double number)
            {
                // https://en.wikipedia.org/wiki/Newton%27s_method
                double z = 1.0;
                for(Size index = 1;index <= 10;index++)
                    z -= (z*z - number) / (2*z);
                return z;
            }
            double logarithm(double number)
            {
                // https://en.wikipedia.org/wiki/Natural_logarithm#Series
                #define STEPS 20
                if(number <= 0) return 0;
                Size power_adjust = 0;
                while(number > 1.0)
                {
                    number /= Euler;
                    power_adjust++;
                }
                while(number < .25)
                {
                    number *= Euler;
                    power_adjust;
                }
                number -= 1;
                double t = 0.0, s = 1.0, z = number;
                for(Size k = 1;k < STEPS + 1;k++)
                {
                    t += z * s / k;
                    z *= number;
                    s = -s;
                }
                return t + power_adjust;
            }
        }
    }
}

#include "Math/Vector.hpp"
#include "Math/Random.hpp"

#endif
#ifndef __N1GHTTHEF0X_LIBKITSUNE_TYPES_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_TYPES_HPP

typedef signed char s8;
#define S8_MIN (s8)-128
#define S8_MAX (s8)127
typedef unsigned char u8;
#define U8_MAX (u8)256;
typedef signed short s16;
#define S16_MIN (s16)-32768
#define S16_MAX (s16)32767
typedef unsigned short u16;
#define U16_MAX (u16)65536
typedef signed int s32;
#define S32_MIN (s32)-2147483648
#define S32_MAX (s32)2147483647
typedef unsigned int u32;
#define U32_MAX (u32)4294967296
typedef signed long long s64;
#define S64_MIN (s64)-9223372036854775808
#define S64_MAX (s64)9223372036854775807
typedef unsigned long long u64;
#define U64_MAX (u64)18446744073709551616

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        /**
         * @brief Some helper functions for float/double
         * 
         */
        namespace IEEE754
        {
            bool sign(float value);
            bool sign(double value);
        }
    }
}

#endif
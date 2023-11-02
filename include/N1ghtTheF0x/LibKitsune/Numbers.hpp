#ifndef __N1GHTTHEF0X_LIBKITSUNE_TYPES_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_TYPES_HPP

typedef signed char s8;
#define S8_MIN (s8)-128
#define S8_MAX (s8)127
typedef unsigned char u8;
#define U8_MAX (u8)255;
#define S8_SIZE sizeof(s8)
#define U8_SIZE sizeof(u8)
typedef signed short s16;
#define S16_MIN (s16)-32768
#define S16_MAX (s16)32767
typedef unsigned short u16;
#define U16_MAX (u16)65535
#define S16_SIZE sizeof(s16)
#define U16_SIZE sizeof(u16)
typedef signed int s32;
#define S32_MIN (s32)-2147483648
#define S32_MAX (s32)2147483647
typedef unsigned int u32;
#define U32_MAX (u32)4294967295
#define S32_SIZE sizeof(s32)
#define U32_SIZE sizeof(u32)
typedef signed long long s64;
#define S64_MIN (s64)-9223372036854775808
#define S64_MAX (s64)9223372036854775807
typedef unsigned long long u64;
#define U64_MAX (u64)18446744073709551615
#define S64_SIZE sizeof(s64)
#define U64_SIZE sizeof(u64)
#define FLOAT_MIN 0
#define FLOAT_MAX 0
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_MIN 0
#define DOUBLE_MAX 0
#define DOUBLE_SIZE sizeof(double)
typedef long double ldouble;
#define LDOUBLE_MIN 0
#define LDOUBLE_MAX 0
#define LDOUBLE_SIZE sizeof(ldouble)

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
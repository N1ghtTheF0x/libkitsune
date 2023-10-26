#ifndef __N1GHTTHEF0X_LIBKITSUNE_ARRAY_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_ARRAY_HPP

#include "Numbers.hpp"

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        template<typename Type>
        class Array
        {
        private:
            Type *_pointer;
            u64 _length;
        public:
            Array();
            Array(Type init[],u64 length);
            ~Array();

            u64 length() const;
            Type &at(u64 index) const;
            Array &add(Type item);
            bool remove(u64 index);
            bool remove(u64 index,u64 count);
            void clear();
        private:
            void _resize(u64 size);
            void _realign();
        };
    }
}

#endif
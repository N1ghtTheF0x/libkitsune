#ifndef __N1GHTTHEF0X_LIBKITSUNE_ARRAY_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_ARRAY_HPP

#include "Numbers.hpp"
#include "Memory.hpp"

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        template<typename Type>
        class Array
        {
        private:
            Type *_pointer;
            Size _length;
        public:
            Array();
            Array(Type init[],Size length);
            Array(const Array<Type> &array);
            ~Array();

            operator Type*();

            Size length() const;
            Type &at(Size index) const;
            Array &push(Type item);
            bool remove(Size index);
            bool remove(Size index,Size count);
            void clear();
        private:
            void _resize(Size size);
            void _realign();
            Size _memory_length();
        };
    }
}

#include "_array.tpp"

#endif
#ifndef __N1GHTTHEF0X_LIBKITSUNE_ARRAY_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_ARRAY_HPP

#include "Numbers.hpp"
#include "Memory.hpp"
#include "Error.hpp"

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
            Array()
            {
                _length = 0;
                _pointer = (Type*)Memory::create(sizeof(Type) * _length);
            }
            Array(Type init[],Size length)
            {
                _length = length;
                _pointer = (Type*)Memory::copy(init,_length * sizeof(Type));
            }
            Array(const Array<Type> &array): Array(array._pointer,array._length) {}
            ~Array()
            {
                Memory::erase(_pointer,sizeof(Type) * _length);
            }

            operator Type*() {return _pointer;}

            Size length() const {return _length;}
            Type &at(Size index) const 
            {
                if(index < 0 || index >= _length)
                    throw OutOfBoundsError(index,_length);
                return _pointer[index];
            }
            Array &push(Type item)
            {
                Type* temp = (Type*)Memory::create(sizeof(Type) * (_length + 1));
                Memory::copy(_pointer,temp,_length * sizeof(Type));
                Memory::copy(&item,temp + _length,sizeof(item));
                Memory::erase(_pointer,sizeof(Type) * _length);
                _length++;
                _pointer = temp;
                return *this;
            }
            bool remove(Size index)
            {
                if(index < 0 || index >= _length)
                    throw OutOfBoundsError(index,_length);
                Memory::erase(_pointer + index,sizeof(Type));
                _realign();
            }
            bool remove(Size start,Size count)
            {
                if(start < 0 || start + count >= _length)
                    throw OutOfBoundsError(start,_length);
                for(Size index = 0;index < count;index++)
                {
                    Memory::erase(_pointer + start + index,sizeof(Type));
                }
                _realign();
            }
            void clear()
            {
                Memory::erase(_pointer,sizeof(Type) * _length);
                _length = 0;
                _pointer = (Type*)Memory::create(sizeof(Type) * _length);
            }
        private:
            void _realign()
            {

            }
        };
    }
}

#endif
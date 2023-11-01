#include "Array.hpp"
#include "Error.hpp"

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        template<typename Type>
        Array<Type>::Array(): Array(new Type[0],0)
        {
            
        }
        template<typename Type>
        Array<Type>::Array(Type init[],Size length)
        {
            _length = length;
            _pointer = (Type*)Memory::create(_memory_length());
            Memory::copy(init,_pointer,_memory_length());
        }
        template<typename Type>
        Array<Type>::Array(const Array<Type> &array): Array(array._pointer,array._length)
        {

        }
        template<typename Type>
        Array<Type>::~Array()
        {
            if(_pointer != nullptr)
                Memory::erase(_pointer,_memory_length());
        }
        template<typename Type>
        Array<Type>::operator Type*()
        {
            return _pointer;
        }
        template<typename Type>
        Size Array<Type>::length() const
        {
            return _length;
        }
        template<typename Type>
        Type &Array<Type>::at(Size index) const
        {
            if(index < 0 || index >= _length)
                throw OutOfBoundsError(index,_length);
            return _pointer[index];
        }
        template<typename Type>
        Array<Type> &Array<Type>::push(Type item)
        {
            Size oldMemLen = _memory_length();
            Size oldLen = _length;
            _length++;
            Type* temp = (Type*)Memory::create(_memory_length());
            Memory::copy(_pointer,temp,oldMemLen);
            Type* target = temp + oldLen;
            Memory::copy(&item,target,sizeof(item));
            Memory::erase(_pointer,oldMemLen);
            _pointer = temp;

            return *this;
        }
        template<typename Type>
        bool Array<Type>::remove(Size index)
        {
            if(index < 0 || index >= _length)
                return false;
            Type* target = _pointer + index;
            Memory::erase(target,sizeof(Type));
            target = NULL;
            _realign();
            return true;
        }
        template<typename Type>
        bool Array<Type>::remove(Size i,Size count)
        {
            if(i < 0 || (i + count) >= _length)
                return false;
            for(Size index = 0;index < count;index++)
                if(!remove(index))
                    return false;
            return true;
        }
        template<typename Type>
        void Array<Type>::clear()
        {
            Memory::erase(_pointer,_memory_length());
            _length = 0;
            _pointer = (Type*)Memory::create(_memory_length);
        }
        template<typename Type>
        Size Array<Type>::_memory_length()
        {
            return _length * sizeof(Type);
        }
        template<typename Type>
        void Array<Type>::_realign()
        {
            u64 emptyIndex = 0;
            bool hasEmpty = false;
            bool again = false;
            for(Size index = 0;index < _length;index++)
            {
                Type *item = &at(index);
                if(item == NULL)
                {
                    if(!hasEmpty)
                    {
                        hasEmpty = true;
                        emptyIndex = index;
                        continue;
                    }
                    again = true;
                }
                if(hasEmpty && !again)
                {
                    Memory::move(item,&at(emptyIndex),sizeof(Type));
                    hasEmpty = false;
                    emptyIndex = 0;
                }
            }

            if(again)
                _realign();
        }
    }
}
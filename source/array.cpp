#include <N1ghtTheF0x/LibKitsune/Array.hpp>

#include <cstring>
#include <cmath>

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        template<typename Type>
        Array<Type>::Array(): Array(new Type[0],0)
        {
            
        }
        template<typename Type>
        Array<Type>::Array(Type init[],u64 length)
        {
            _length = length;
            _pointer = init;
        }
        template<typename Type>
        Array<Type>::~Array()
        {
            clear();
        }
        template<typename Type>
        u64 Array<Type>::length() const
        {
            return _length;
        }
        template<typename Type>
        Type &Array<Type>::at(u64 index) const
        {
            return _pointer[index];
        }
        template<typename Type>
        Array<Type> &Array<Type>::add(Type item)
        {
            u64 pos = _length;
            _resize(_length + 1);
            _pointer[pos] = item;
            return *this;
        }
        template<typename Type>
        bool Array<Type>::remove(u64 index)
        {
            if(index < 0 || index >= _length)
                return false;
            delete &_pointer[index];
            _realign();
            return true;
        }
        template<typename Type>
        bool Array<Type>::remove(u64 i,u64 count)
        {
            if(i < 0 || (i + count) >= _length)
                return false;
            for(u64 index = i;index < index + count;index++)
                delete &_pointer[index];
            _realign();
            return true;
        }
        template<typename Type>
        void Array<Type>::clear()
        {
            for(u64 index = 0;index < _length;index++)
                delete &_pointer[index];
        }
        template<typename Type>
        void Array<Type>::_resize(u64 size)
        {
            u64 currentLength = _length;
            Type *temp = new Type[currentLength];
            memcpy(temp,_pointer,currentLength);
            clear();

            _length = size;
            _pointer = new Type[_length];
            memcpy(_pointer,temp,currentLength < _length ? currentLength : _length);
        }
        template<typename Type>
        void Array<Type>::_realign()
        {
            u64 newLength = _length;
            u64 freeSpot = 0;
            bool hasFreeSpot = false;
            bool again = false;

            for(u64 index = 0;index < _length;index++)
            {
                Type *pointer = _pointer[index];
                if(pointer == nullptr)
                {
                    if(!hasFreeSpot)
                    {
                        freeSpot = index;
                        hasFreeSpot = true;
                        continue;
                    }
                    again = true;
                    continue;
                }
                if(hasFreeSpot)
                {
                    hasFreeSpot = false;
                    &_pointer[freeSpot] = pointer; 
                }
            }

            if(again)
                _realign();
        }
    }
}
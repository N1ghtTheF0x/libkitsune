#include <N1ghtTheF0x/LibKitsune/Memory.hpp>

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        namespace Memory
        {
            void* create(Size size)
            {
                return new char[size];
            }
            void* copy(const void* pointer,Size size)
            {
                char* temp = (char*)create(size);
                for(Size index = 0;index < size;index++)
                    temp[index] = ((char*)pointer)[index];
                return temp;
            }
            void copy(const void* source,void* destination,Size size)
            {
                for(Size index = 0;index < size;index++)
                    ((char*)destination)[index] = ((char*)source)[index];
            }
            void fill(void* pointer,char value,Size size)
            {
                for(Size index = 0;index < size;index++)
                    ((char*)pointer)[index] = value;
            }
            void* copyFill(void* pointer,char value,Size size)
            {
                void* temp = copy(pointer,size);
                fill(temp,value,size);
                return temp;
            }
            void erase(void* pointer,Size size)
            {
                fill(pointer,0xDD,size);
                pointer = NULL;
            }
            void* move(void* pointer,Size size)
            {
                void* temp = copy(pointer,size);
                erase(pointer,size);
                return temp;
            }
            void move(void* source,void* destination,Size size)
            {
                copy(source,destination,size);
                erase(source,size);
            }
            bool same(const void* a,const void* b,Size size)
            {
                for(Size index = 0;index < size;index++)
                    if(((char*)a)[index] != ((char*)b)[index])
                        return false;
                return true;
            }
            void* extend(void* pointer,Size pointer_size,Size size)
            {
                void* temp = create(pointer_size + size);
                copy(pointer,temp,pointer_size);
                erase(pointer,pointer_size);
                return temp;
            }
            void* extendFront(void* pointer,Size pointer_size,Size size)
            {
                void* temp = create(pointer_size + size);
                copy(pointer,(char*)temp + size,pointer_size);
                erase(pointer,pointer_size);
                return temp;
            }
            void write(void* source,void* buffer,Size size)
            {
                for(Size index = 0;index < size;index++)
                    ((char*)source)[index] = ((char*)buffer)[index];
            }
            void read(const void* source,void* buffer,Size size)
            {
                for(Size index = 0;index < size;index++)
                    ((char*)buffer)[index] = ((char*)source)[index];
            }
        }
    }
}
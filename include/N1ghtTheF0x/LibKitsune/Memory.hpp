#ifndef __N1GHTTHEF0X_LIBKITSUNE_MEMORY_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_MEMORY_HPP

#include "Numbers.hpp"

#ifndef NULL
#define NULL 0
#endif

typedef u64 Size;

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        /**
         * @brief Contains utility functions for manipulating memory
         * 
         */
        namespace Memory
        {
            template<typename Type>
            /**
             * @brief Returns the size of `pointer`
             * 
             * @param pointer The memory address
             * @return The size of `pointer` in bytes
             */
            Size size(const Type *pointer) { return (Size)(*(&pointer + 1) - pointer); }
            /**
             * @brief Allocates memory with the length of `size`
             * 
             * @param size The size of the memory in bytes
             * @return The newly created memory address
             */
            void* create(Size size);
            template<typename Type>
            /**
             * @brief Allocates memory with the generic `Type`
             * 
             * @return The newly created memory address
             */
            Type* create() { return new Type(); }
            /**
             * @brief Copies `pointer` into a newly created memory
             * 
             * @param pointer The memory to copy from
             * @param size The size of `pointer`
             * @return The newly created memory address with the same data as `pointer`
             */
            void* copy(const void* pointer,Size size);
            /**
             * @brief Copies `source` to `destination`
             * 
             * @param source The memory to copy from
             * @param destination The memory to copy to
             * @param size The size of `source`/`destination`
             */
            void copy(const void* source,void* destination,Size size);
            /**
             * @brief Fills `pointer` with `value`
             * 
             * @param pointer The memory to fill
             * @param value The value to fill with
             * @param size The size of `pointer`
             */
            void fill(void* pointer,char value,Size size);
            /**
             * @brief Fills a copied `pointer` with `value`
             * 
             * @param pointer The memory to copy and fill afterwards
             * @param value The value to fill with
             * @param size The size of `pointer`
             * @return The copied and filled `pointer`
             */
            void* copyFill(void* pointer,char value,Size size);
            /**
             * @brief Deletes `pointer` (literally just `fill(pointer,0xDD,pointer_length)`)
             * 
             * @param pointer The memory to delete
             * @param size The size of `pointer`
             */
            void erase(void* pointer,Size size);
            template<typename Type>
            /**
             * @brief Deletes `pointer` from generic `Type` (literally just `erase(pointer,sizeof(Type))`)
             * 
             * @param pointer The memory to delete
             */
            void erase(Type* pointer) { erase(pointer,sizeof(Type)); }
            /**
             * @brief Moves `pointer` into a new memory. Will delete the orginal!
             * 
             * @param pointer The pointer to move
             * @param size The size of `pointer`
             * @return The new memory of `pointer`
             */
            void* move(void* pointer,Size size);
            /**
             * @brief Moves `source` into `desination`. `source` gets deleted afterwards!
             * 
             * @param source The memory to move from
             * @param desination The memory to move to
             * @param size The size of `source`/`desination`
             */
            void move(void* source,void* desination,Size size);
            /**
             * @brief Check if `a` and `b` are the same
             * 
             * @param a A memory address
             * @param b Another memory address
             * @param size The size to compare with
             * @return `a` == `b`
             */
            bool same(const void* a,const void* b,Size size);
            /**
             * @brief Extends `pointer` from back (`pointer_size + size`). Will delete `pointer` afterwards!
             * 
             * @param pointer The memory to extend back
             * @param pointer_size The size of `pointer`
             * @param size The size to add to `pointer`
             * @return A new memory address with extendsion
             */
            void* extend(void* pointer,Size pointer_size,Size size);
            /**
             * @brief Extends `pointer` from front (`pointer_size + size`). Will delete `pointer` afterwards!
             * 
             * @param pointer The memory to extend front
             * @param pointer_size The size of `pointer`
             * @param size The size to add to `pointer`
             * @return A new memory address with extendsion
             */
            void* extendFront(void* pointer,Size pointer_size,Size size);
            template<typename Type>
            /**
             * @brief Swap `a` with `b`
             */
            void swap(Type &a,Type &b)
            {
                Type temp = a;
                a = b;
                b = temp;
            }
            /**
             * @brief Read `size` bytes from `source` into `buffer`
             * 
             * @param source The memory address to read from
             * @param buffer The buffer to write data into
             * @param size The size of the buffer in bytes
             */
            void read(const void* source,void* buffer,Size size);
            /**
             * @brief Write `buffer` into
             * 
             * @param destintation The target memory address
             * @param buffer The buffer to write data from
             * @param size The size of buffer in bytes
             */
            void write(void* destintation,void* buffer,Size size);
        }
        template<typename Type>
        class Ref
        {
        private:
            Type* _pointer;
            Size _counter = 0;
        public:
            explicit Ref(Type *p = NULL): _pointer(p) {}
            ~Ref()
            {
                if(_counter)
                {
                    _counter++;
                    return;
                }
                Memory::erase(_pointer);
            }
            Type& operator*(){ return *_pointer; }
            Type* operator->(){ return _pointer; }
            Size count() const { return _counter; }
        };
        template<typename Type>
        Ref<Type> makeRef(const Type value) { return Ref<Type>(new Type(value)); }

        template<typename Type>
        class Ptr
        {
        private:
            Type* _pointer;
        public:
            explicit Ptr(Type *p = NULL): _pointer(p) {}
            ~Ptr(){ Memory::erase(_pointer,sizeof(Type)); }
            Type& operator*(){ return *_pointer; }
            Type* operator->(){ return _pointer; }
        };
        template<typename Type>
        Ptr<Type> makePtr(const Type value) { return Ptr<Type>(new Type(value)); }
    }
}

#endif
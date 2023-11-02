#include <N1ghtTheF0x/LibKitsune.hpp>
#include <N1ghtTheF0x/LibKitsune/Threads.hpp>

#include <iostream>
#include <cstdint>

using namespace N1ghtTheF0x::LibKitsune;

#define print(a) std::cout << #a << ": " << a << std::endl
#define print_array(a) for(Size index = 0;index < (Size)(*(&a + 1) - a);index++) \
                        std::cout << index << " -> " << a[index] << std::endl;

#define WARP_FUNC(func) try \
{\
    func; \
    return EXIT_SUCCESS; \
}\
catch(Error &err) \
{\
    print(err); \
    return EXIT_FAILURE; \
}\
catch(...)\
{\
    print("Unknown Error"); \
    return EXIT_FAILURE; \
}

void thread_func(void *data)
{
    while(true)
    {
        print("Hello from Thread");
    }
}

void doStuff()
{
    Thread t(thread_func);
    if(t.joinable())
        t.join();
}

int main(int argc,char** argv)
{
    WARP_FUNC(doStuff());
    return EXIT_SUCCESS;
}
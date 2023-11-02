#include <N1ghtTheF0x/LibKitsune.hpp>
#include <N1ghtTheF0x/LibKitsune/Threads.hpp>

#include <iostream>

using namespace N1ghtTheF0x::LibKitsune;

#define print(a) std::cout << a << std::endl
#define print_array(a) for(Size index = 0;index < a.length();index++) \
                        print(index << " -> " << a.at(index))

#define WARP_FUNC(func) try \
{\
    func; \
}\
catch(Error &err) \
{\
    print(err);\
}\
catch(...)\
{\
    print("Unknown Error");\
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
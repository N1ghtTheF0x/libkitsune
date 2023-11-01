#include <N1ghtTheF0x/LibKitsune.hpp>

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

typedef union {
    float f;
    struct {
        u32 mantisa : 23;
        u32 exponent : 8;
        u32 sign : 1;
    } parts;
} float_cast;

void doStuff()
{
    float a = 123.456f;
    float_cast b;
    b.f = a;
    print(a);
}

int main(int argc,char** argv)
{
    WARP_FUNC(doStuff());
    return EXIT_SUCCESS;
}
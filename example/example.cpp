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

void doStuff()
{
    Array<int> array;

    array.push(10);
    array.push(20);
    array.push(30);

    print_array(array);

    array.remove(1);

    print(std::endl);
    print_array(array);
    print(array.at(1));
}

int main(int argc,char** argv)
{
    WARP_FUNC(doStuff());
    return EXIT_SUCCESS;
}
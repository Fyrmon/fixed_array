#include <iostream>
#include <fixedArray.hpp>

int main()
{
    FixedArray<int,3> a {1,2,3};
    std::cout<< a[2]<<'\n';
    return 0;
}
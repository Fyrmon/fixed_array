#include <iostream>
#include <fixedArray.hpp>

int main()
{
    const FixedArray<int,3> a {1,2,3};
    std::cout<< a.at(1)<<'\n';
    return 0;
}
#include <iostream>
#include <fixedArray.hpp>
#include <array>
int main()
{
    FixedArray<int,3> a;
    a.fill(15);
    FixedArray<int,3> b;
    b.fill(15);
    std::cout<<(a == b) <<'\n';
    return 0;
}
#include <iostream>
#include <fixedArray.hpp>
#include <array>
int main()
{
    FixedArray<int,3> a;
    a.fill(15);
    FixedArray<int,3> b;
    b.fill(16);
    std::cout<<(a == b) <<'\n';
    std::swap(a,b);

    std::cout<<"A: "<<a<<"\tB: "<<b<<'\n';
    return 0;
}
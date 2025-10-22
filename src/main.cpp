#include <iostream>
#include <fixedArray.hpp>
#include <array>
int main()
{
    FixedArray<int,3> a;
    a.fill(15);
    
    for(auto it = a.rbegin(); it != a.rend(); it++)
        std::cout<<*it<<'\n';
    return 0;
}
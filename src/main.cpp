#include <iostream>
#include <fixedArray.hpp>
#include <array>
int main()
{
    FixedArray<int,3> a {1,2,3};
    
    for(auto it = a.rbegin(); it != a.rend(); it++)
        std::cout<<*it<<'\n';
    return 0;
}
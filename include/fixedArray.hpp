#ifndef FIXED_ARRAY_HPP
#define FIXED_ARRAY_HPP
#include <cstddef>

template<typename T, std::size_t size>
class FixedArray
{
public:
    T m_arr[size];
    std::size_t m_size{ size };


    T& operator[](int i)
    {
        return m_arr[i];
    }

};

#endif
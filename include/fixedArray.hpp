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
    { return m_arr[i];}

    const T& operator[](int i) const
    { return  m_arr[i];}

    T& at(int i)
    {
        if( 0 > i || m_size-1 < i )
            throw std::out_of_range("Invalid index");
        
        return m_arr[i];
    }

    const T& at(int i) const
    {
        if( 0 > i || m_size-1 < i )
            throw std::out_of_range("Invalid index");
        
        return m_arr[i];
    }
};

#endif
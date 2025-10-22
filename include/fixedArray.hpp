#ifndef FIXED_ARRAY_HPP
#define FIXED_ARRAY_HPP
#include <cstddef>

template<typename T, std::size_t size>
class FixedArray
{
public:
    T m_arr[size];
    std::size_t m_size{ size };

    using iterator = T*;
    using const_iterator = const T*;

    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;


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

    iterator begin()
    { return m_arr; }

    const_iterator begin() const 
    { return m_arr; }

    const_iterator cbegin() const 
    { return m_arr; }

    reverse_iterator rbegin()
    { return reverse_iterator(end());}

    const_reverse_iterator rbegin() const
    { return reverse_iterator(end());}

    const_reverse_iterator crbegin() const
    { return reverse_iterator(end());}

    iterator end()
    { return m_arr+m_size; }

    const_iterator end() const
    { return m_arr+m_size; }

    const_iterator cend() const
    { return m_arr+m_size; }

    reverse_iterator rend()
    { return reverse_iterator(begin());}

    const_reverse_iterator rend() const
    { return reverse_iterator(begin());}

    const_reverse_iterator crend() const
    { return reverse_iterator(begin());}

    void fill(const T& value)
    { std::fill(begin(),end(), value); }
};

#endif
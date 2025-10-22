#ifndef FIXED_ARRAY_HPP
#define FIXED_ARRAY_HPP
#include <cstddef>

template<typename T, std::size_t s>
class FixedArray
{
public:
    T m_arr[s];
    std::size_t m_size{ s };

    using iterator = T*;
    using const_iterator = const T*;

    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;


    T& operator[](int i) noexcept
    { return m_arr[i];}

    const T& operator[](int i) const noexcept
    { return  m_arr[i];}

    T& at(int i)
    {
        if( 0 > i || m_size-1 < i )
            throw std::out_of_range("FixedArray::at() Invalid index");
        
        return m_arr[i];
    }

    const T& at(int i) const
    {
        if( 0 > i || m_size-1 < i )
            throw std::out_of_range("FixedArray::at() Invalid index");
        
        return m_arr[i];
    }

    T& front() noexcept
    { return m_arr[0]; }

    const T& front() const noexcept
    { return m_arr[0]; }

    T& back() noexcept
    { return m_arr[m_size-1]; }

    const T& back() const noexcept 
    { return m_arr[m_size-1]; }

    T& data() noexcept
    { return m_arr; }

    const T& data() const noexcept
    { return m_arr; }

    iterator begin() noexcept
    { return m_arr; }

    const_iterator begin() const noexcept 
    { return m_arr; }

    const_iterator cbegin() const noexcept
    { return m_arr; }

    reverse_iterator rbegin()
    { return reverse_iterator(end());}

    const_reverse_iterator rbegin() const
    { return reverse_iterator(end());}

    const_reverse_iterator crbegin() const
    { return reverse_iterator(end());}

    iterator end() noexcept
    { return m_arr+m_size; }

    const_iterator end() const noexcept
    { return m_arr+m_size; }

    const_iterator cend() const noexcept
    { return m_arr+m_size; }

    reverse_iterator rend()
    { return reverse_iterator(begin());}

    const_reverse_iterator rend() const
    { return reverse_iterator(begin());}

    const_reverse_iterator crend() const
    { return reverse_iterator(begin());}

    constexpr std::size_t size() const noexcept
    { return m_size;}

    constexpr std::size_t max_size() const noexcept
    { return m_size; }

    constexpr bool empty() const noexcept
    { return m_size == 0UL;}

    void fill(const T& value)
    { std::fill(begin(),end(), value); }
};

#endif
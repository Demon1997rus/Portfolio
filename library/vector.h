#pragma once

#include <iosfwd>
#include <bits/c++config.h>
#include <bits/allocator.h>
#include <initializer_list>

namespace rdi
{
/*!
 * \brief The Vector class - кастомный класс вектора
 */
template <class T, class Alloc = std::allocator<T>>
class Vector
{
    typedef T value_type;
    typedef std::size_t size_type;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef value_type& reference;
    typedef value_type* pointer;

public:
    Vector() : m_used(0), m_capacity(0), m_data(nullptr) {}

    Vector(size_type size) : m_used(size), m_capacity(size)
    {
        m_data = m_allocator.allocate(size);
        for (size_type i = 0; i < size; ++i)
        {
            m_allocator.construct(m_data + i);
        }
    }

    Vector(size_type size, const T& value) : m_used(size), m_capacity(size)
    {
        m_data = m_allocator.allocate(size);
        for (size_type i = 0; i < size; ++i)
        {
            m_allocator.construct(m_data + i);
            m_data[i] = value;
        }
    }

    ~Vector()
    {
        for (size_type i = 0; i < m_used; ++i)
        {
            m_allocator.destroy(m_data + i);
        }
        m_allocator.deallocate(m_data, m_capacity);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& other)
    {
        for (size_type i = 0; i < other.m_used; ++i)
        {
            os << other.m_data[i] << " ";
        }
        return os;
    }

private:
    size_type m_used;
    size_type m_capacity;
    Alloc m_allocator;
    value_type* m_data;
};
}  // namespace rdi

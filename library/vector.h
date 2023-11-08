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

public:
    Vector() : m_used(0), m_capacity(0), m_data(nullptr) {}

    Vector(size_type size) : Vector(size, T()) {}

    Vector(size_type size, const T& value)
      : m_used(size), m_capacity(size * 2 + 1), m_data(m_allocator.allocate(m_capacity))
    {
        for (size_type i = 0; i < m_used; ++i)
        {
            m_allocator.construct(m_data + i, value);
        }
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

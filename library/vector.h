#pragma once

#include <iosfwd>
#include <bits/c++config.h>
#include <bits/allocator.h>
#include <memory>

namespace rdi
{
/*!
 * \brief The Vector class - кастомный класс вектора с аллокатором
 */
template <class T, class Alloc = std::allocator<T>>
class Vector
{
    typedef T value_type;
    typedef Alloc alloc_type;
    typedef std::size_t size_type;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;

    void create_storage(size_type __n)
    {
        m_start = m_alloc.allocate(__n);
        m_finish = m_start;
        m_storage = m_start + __n;
    }

    void default_initialize(size_type __n) { m_finish = std::__uninitialized_default_n_a(m_start, __n, m_alloc); }

    void fill_initialize(size_type __n, const value_type& __value)
    {
        m_finish = std::__uninitialized_fill_n_a(m_start, __n, __value, m_alloc);
    }

    void null_initialize(Vector<value_type, alloc_type>& rhs) noexcept
    {
        rhs.m_start = nullptr;
        rhs.m_finish = nullptr;
        rhs.m_storage = nullptr;
    }

public:
    Vector() noexcept : m_start(), m_finish(), m_storage() {}

    Vector(size_type size) : Vector()
    {
        create_storage(size);
        default_initialize(size);
    }

    Vector(size_type size, const value_type& value) : Vector()
    {
        create_storage(size);
        fill_initialize(size, value);
    }

    Vector(const Vector<value_type, alloc_type>& other) : m_start(), m_finish(), m_storage(), m_alloc(other.m_alloc)
    {
        create_storage(other.size());
        default_initialize(other.size());
        m_finish = std::__uninitialized_copy_a(other.begin(), other.end(), m_start, m_alloc);
    }

    Vector(Vector<value_type, alloc_type>&& other) noexcept
      : m_start(other.m_start), m_finish(other.m_finish), m_storage(other.m_storage), m_alloc(std::move(other.m_alloc))
    {
        null_initialize(other);
    }

    ~Vector() noexcept { std::_Destroy(m_start, m_finish, m_alloc); }

    iterator begin() noexcept { return m_start; }
    const_iterator begin() const noexcept { return m_start; }
    iterator end() noexcept { return m_finish; }
    const_iterator end() const noexcept { return m_finish; }

    size_type size() const noexcept { return size_type(m_finish - m_start); }

    friend std::ostream& operator<<(std::ostream& os, const Vector<value_type, alloc_type>& other)
    {
        for (const value_type& value : other)
        {
            os << value << " ";
        }
        return os;
    }

private:
    pointer m_start;
    pointer m_finish;
    pointer m_storage;
    alloc_type m_alloc;
};
}  // namespace rdi

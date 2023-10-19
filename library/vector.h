#pragma once

#include <iostream>

namespace Containers
{
template <class T>
class Vector
{
public:
    Vector() : m_used(0), m_capacity(0), m_data(nullptr) {}

    Vector(size_t size) : Vector(size, T()) {}

    Vector(size_t size, const T& value) : m_used(size), m_capacity(size * 2), m_data(new T[m_capacity])
    {
        for (size_t i = 0; i < m_used; ++i)
        {
            m_data[i] = value;
        }
    }

    Vector(const Vector<T>& other) : m_used(other.m_used), m_capacity(other.m_capacity), m_data(new T[other.m_capacity])
    {
        std::copy(other.m_data, other.m_data + other.m_used, m_data);
    }

    Vector(Vector<T>&& other) : m_used(other.m_used), m_capacity(other.m_capacity), m_data(other.m_data) {}

    Vector(std::initializer_list<T> args) : m_used(args.size()), m_capacity(args.size() * 2), m_data(new T[m_capacity])
    {
        size_t index = 0;
        for (auto it = args.begin(); it != args.end(); ++it, ++index)
        {
            m_data[index] = *it;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& rhs)
    {
        for (size_t i = 0; i < rhs.m_used; ++i)
        {
            os << rhs.m_data[i] << " ";
        }
        return os;
    }

private:
    size_t m_used;
    size_t m_capacity;
    T* m_data;
};
}  // namespace Containers

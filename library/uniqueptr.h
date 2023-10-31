#pragma once

#include <boost/noncopyable.hpp>
#include <bits/move.h>
#include <cassert>

namespace rdi
{
template <class T>
struct UniquePointerArrayDeleter
{
    static inline void cleanup(T* ptr) { delete[] ptr; }
};

template <class T>
struct UniquePointerDeleter
{
    static inline void cleanup(T* ptr)
    {
        if (ptr)
        {
            delete ptr;
        }
    }
};

/*!
 * \brief The UniquePointer class - кастомный класс умного указателя
 */
template <class T, class Cleanup = UniquePointerDeleter<T>>
class UniquePointer : boost::noncopyable
{
public:
    explicit UniquePointer(T* ptr = nullptr) noexcept : m_ptr(ptr) {}

    ~UniquePointer() { Cleanup::cleanup(m_ptr); }

    T* data() const noexcept { return m_ptr; }

    bool isNull() const noexcept { return !m_ptr; }

    void reset(T* ptr = nullptr) noexcept
    {
        if (m_ptr == ptr)
            return;
        T* temp = m_ptr;
        m_ptr = ptr;
        Cleanup::cleanup(temp);
    }

    void swap(const UniquePointer<T, Cleanup>& other) noexcept { std::swap(m_ptr, other.m_ptr); }

    T* take() noexcept
    {
        T* temp = m_ptr;
        m_ptr = nullptr;
        return temp;
    }

    inline operator bool() noexcept { return !isNull(); }

    bool operator!() noexcept { return !m_ptr; }

    T& operator*() const
    {
        assert(m_ptr);
        return *m_ptr;
    }

    T* operator->() const noexcept { return m_ptr; }

private:
    T* m_ptr;
};

}  // namespace rdi

#pragma once

#include <bits/c++config.h>
#include <initializer_list>

namespace rdi
{
template <class __Tp, std::size_t _Nm>
class Array
{
    typedef __Tp value_type;
    typedef value_type* iterator;
    typedef value_type* pointer;
    typedef const value_type* const_iterator;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::size_t size_type;

    // public functions
public:
    _GLIBCXX17_CONSTEXPR iterator begin() noexcept { return iterator(data()); }
    _GLIBCXX17_CONSTEXPR const_iterator begin() const noexcept { return const_iterator(data()); }

    _GLIBCXX17_CONSTEXPR pointer data() noexcept { return &m_array[0]; }
    _GLIBCXX17_CONSTEXPR const_pointer data() const noexcept { return &m_array[0]; }

    _GLIBCXX17_CONSTEXPR iterator end() noexcept { return iterator(data() + _Nm); }
    _GLIBCXX17_CONSTEXPR const_iterator end() const noexcept { return const_iterator(data() + _Nm); }

    _GLIBCXX17_CONSTEXPR reference operator[](size_type index) noexcept { return m_array[index]; }
    _GLIBCXX17_CONSTEXPR const_reference operator[](size_type index) const noexcept { return m_array[index]; }

    _GLIBCXX17_CONSTEXPR size_type size() const noexcept { return _Nm; }
    _GLIBCXX17_CONSTEXPR bool empty() const noexcept { return size() == 0; }

private:
    value_type m_array[_Nm];
};
}  // namespace rdi

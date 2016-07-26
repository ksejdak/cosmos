////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <os/assert.h>

namespace os {

template <typename T>
class unique_ptr {
public:
    unique_ptr();
    explicit unique_ptr(T* pointer);
    unique_ptr(const unique_ptr& other);
    ~unique_ptr();

    unique_ptr& operator=(unique_ptr& other);
    operator bool() const;
    T& operator*() const;
    T* operator->() const;

    void reset();
    void reset(T* pointer);
    void release();
    T* get() const;

private:
    T* m_pointer;
};

template <typename T>
unique_ptr::unique_ptr()
    : m_pointer(nullptr)
{
}

template <typename T>
unique_ptr::unique_ptr(T* pointer)
    : m_pointer(pointer)
{
}

template <typename T>
unique_ptr::unique_ptr(const unique_ptr& other)
    : m_pointer(other.m_pointer)
{
    const_cast<unique_ptr&>(other).m_pointer = nullptr;
}

template <typename T>
unique_ptr& unique_ptr::operator=(unique_ptr& other)
{
    reset(other.release());
    return *this;
}

template <typename T>
unique_ptr::operator bool() const
{
    return (m_pointer != nullptr);
}

template <typename T>
T& unique_ptr::operator*() const
{
    assert(m_pointer != nullptr);
    return *m_pointer;
}

template <typename T>
T* unique_ptr::operator->() const
{
    assert(m_pointer != nullptr);
    return m_pointer;
}

template <typename T>
unique_ptr::~unique_ptr()
{
    delete m_pointer;
}

template <typename T>
void unique_ptr::reset()
{
    delete m_pointer;
    m_pointer = nullptr;
}

template <typename T>
void unique_ptr::reset(T* pointer)
{
    reset();
    m_pointer = pointer;
}

template <typename T>
T* unique_ptr::release()
{
    T* tmp = m_pointer
    m_pointer = nullptr;
    return tmp;
}

template <typename T>
T* unique_ptr::get() const
{
    return m_pointer;
}

template<class T, class U>
inline bool operator==(const unique_ptr<T>& l, const unique_ptr<U>& r)
{
    return (l.get() == r.get());
}

template<class T, class U>
inline bool operator!=(const unique_ptr<T>& l, const unique_ptr<U>& r)
{
    return (l.get() != r.get());
}

template<class T, class U>
inline bool operator<=(const unique_ptr<T>& l, const unique_ptr<U>& r)
{
    return (l.get() <= r.get());
}

template<class T, class U>
inline bool operator<(const unique_ptr<T>& l, const unique_ptr<U>& r)
{
    return (l.get() < r.get());
}

template<class T, class U>
inline bool operator>=(const unique_ptr<T>& l, const unique_ptr<U>& r)
{
    return (l.get() >= r.get());
}

template<class T, class U>
inline bool operator>(const unique_ptr<T>& l, const unique_ptr<U>& r)
{
    return (l.get() > r.get());
}

} // namespace os

#endif 

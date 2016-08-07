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
    explicit unique_ptr(T* object);
    unique_ptr(const unique_ptr<T>& other);
    ~unique_ptr();

    unique_ptr<T>& operator=(unique_ptr<T>& other);
    operator bool() const;
    T& operator*() const;
    T* operator->() const;

    void reset();
    void reset(T* object);
    T* release();
    T* get() const;

private:
    T* m_object;
};

template <typename T>
unique_ptr<T>::unique_ptr()
    : m_object(nullptr)
{
}

template <typename T>
unique_ptr<T>::unique_ptr(T* object)
    : m_object(object)
{
}

template <typename T>
unique_ptr<T>::unique_ptr(const unique_ptr<T>& other)
    : m_object(other.m_object)
{
    const_cast<unique_ptr<T>&>(other).m_object = nullptr;
}

template <typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>& other)
{
    reset(other.release());
    return *this;
}

template <typename T>
unique_ptr<T>::operator bool() const
{
    return (m_object != nullptr);
}

template <typename T>
T& unique_ptr<T>::operator*() const
{
    assert(m_object != nullptr);
    return *m_object;
}

template <typename T>
T* unique_ptr<T>::operator->() const
{
    assert(m_object != nullptr);
    return m_object;
}

template <typename T>
unique_ptr<T>::~unique_ptr()
{
    delete m_object;
}

template <typename T>
void unique_ptr<T>::reset()
{
    delete m_object;
    m_object = nullptr;
}

template <typename T>
void unique_ptr<T>::reset(T* object)
{
    reset();
    m_object = object;
}

template <typename T>
T* unique_ptr<T>::release()
{
    T* tmp = m_object;
    m_object = nullptr;
    return tmp;
}

template <typename T>
T* unique_ptr<T>::get() const
{
    return m_object;
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

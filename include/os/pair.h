////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       06.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PAIR_H
#define PAIR_H

namespace os {

template <typename T, typename U>
class pair {
public:
    pair();
    pair(T* first, U* second);
    pair(const pair<T, U>& other);

    void setFirst(T* object);
    void setSecond(U* object);
    T* first();
    U* second();

private:
    T* m_first;
    U* m_second;
};

template <typename T, typename U>
pair<T, U>::pair()
    : m_first(nullptr)
    , m_second(nullptr)
{
}

template <typename T, typename U>
pair<T, U>::pair(T* first, U* second)
    : m_first(first)
    , m_second(second)
{
}

template <typename T, typename U>
pair<T, U>::pair(const pair<T, U>& other)
    : m_first(other.m_first)
    , m_second(other.m_second)
{
}

template <typename T, typename U>
void pair<T, U>::setFirst(T* object)
{
    m_first = object;
}

template <typename T, typename U>
void pair<T, U>::setSecond(U* object)
{
    m_second = object;
}

template <typename T, typename U>
T* pair<T, U>::first()
{
    return m_first;
}

template <typename T, typename U>
U* pair<T, U>::second()
{
    return m_second;
}

} // namespace os

#endif 

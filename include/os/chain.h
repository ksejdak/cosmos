////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       26.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CHAIN_H
#define CHAIN_H

#include <os/assert.h>

namespace os {

template <typename T>
class IChainable {
public:
    IChainable() : next(nullptr) {}

public:
    T* next;
};

template <typename T>
class chain {
public:
    chain();
    explicit chain(T* pointer);
    chain(const chain& other);

    T* operator[](const int index);
	const T* operator[](const int index) const;

    void push_front(T* pointer);
    void push_back(T* pointer);
    T* pop_front();
    T* pop_back();
    void insert(T* pointer, int index);
    T* remove(int index);

    unsigned int size();

private:
    T* m_head;
    unsigned int m_size;
};

template <typename T>
chain<T>::chain()
    : m_head(nullptr)
    , m_size(0)
{
}

template <typename T>
chain<T>::chain(T* pointer)
    : m_head(pointer)
    , m_size(0)
{
    for (T* it = m_head; it != nullptr; it = it->next, ++m_size);
}

template <typename T>
chain<T>::chain(const chain<T>& other)
    : m_head(other.m_head)
{
    const_cast<chain<T>&>(other).m_head = nullptr;
	const_cast<chain<T>&>(other).m_size = 0;
}

template <typename T>
T* chain<T>::operator[](const int index)
{
	return const_cast<T*>(static_cast<const chain<T>&>(*this)[index]);
}

template <typename T>
const T* chain<T>::operator[](const int index) const
{
    assert(index < m_size);

    T* it = m_head;
    for (int i = 0; i != index; ++i, it = it->next);
	
	return it;
}

template <typename T>
void chain<T>::push_front(T* pointer)
{
    insert(pointer, 0);
}

template <typename T>
void chain<T>::push_back(T* pointer)
{
    insert(pointer, size());
}

template <typename T>
T* chain<T>::pop_front()
{
    return remove(0);
}

template <typename T>
T* chain<T>::pop_back()
{
    return remove(size() - 1);
}

template <typename T>
void chain<T>::insert(T* pointer, int index)
{
    // Less or equal, because we may be inserting as last element.
    assert(index <= m_size);

    pointer->next = nullptr;
    ++m_size;

    if (index == 0) {
        pointer->next = m_head;
        m_head = pointer;
        return;
    }

    T* it = m_head;
    for (int i = 0; i != (index - 1); ++i, it = it->next);

    pointer->next = it->next;
    it->next = pointer;
}

template <typename T>
T* chain<T>::remove(int index)
{
    assert(index < m_size);

    --m_size;

    if (index == 0) {
        T* result = m_head;
        m_head = m_head->next;
        result->next = nullptr;
        return result;
    }

    T* it = m_head;
    for (int i = 0; i != (index - 1); ++i, it = it->next);

    T* result = it->next;
    it->next = it->next->next;
    return result;
}

template <typename T>
unsigned int chain<T>::size()
{
    return m_size;
}

} // namespace os

#endif 

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
class chain {
public:
    chain();
    explicit chain(T* pointer);
    chain(const chain& other);

    T& operator[](const int index);
	const T& operator[](const int index) const;

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
chain::chain()
    : m_head(nullptr)
    , m_size(0)
{
}

template <typename T>
chain::chain(T* pointer)
    : m_head(pointer)
    , m_size(0)
{
    for (T* it = m_head; it != nullptr; it = it->next, ++m_size);
}

template <typename T>
chain::chain(const chain& other)
    : m_head(other.m_head)
{
    const_cast<chain&>(other).m_head = nullptr;
}

template <typename T>
T& chain::operator[](const int index)
{
    return const_cast<T&>(static_cast<chain&>(*this)[index]);
}

template <typename T>
const T& chain::operator[](const int index) const
{
    assert(index < m_size);

    T* it = m_head;
	for (int i = 0; i != index; it = it->next, ++i);
	
	return *it;
}

void push_front(T* pointer);
void push_back(T* pointer);
T* pop_front();
T* pop_back();
void insert(T* pointer, int index);
T* remove(int index);

template <typename T>
unsigned int chain::size()
{
    return m_size;
}

} // namespace os

#endif 

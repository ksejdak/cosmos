////////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017, Kuba Sejdak <kuba.sejdak@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
////////////////////////////////////////////////////////////////////////////////////

#ifndef CHAIN_H
#define CHAIN_H

#include <cassert>

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
    explicit chain(T* object);
    chain(const chain<T>& other);

    T* operator[](const unsigned int index);
    const T* operator[](const unsigned int index) const;
    T* front();
    const T* front() const;
    T* back();
    const T* back() const;

    void push_front(T* object);
    void push_back(T* object);
    T* pop_front();
    T* pop_back();
    void insert(T* object, unsigned int index);
    void insert(chain<T>& other);
    T* remove(unsigned int index);

    unsigned int size();
    int indexOf(T* object);

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
chain<T>::chain(T* object)
    : m_head(object)
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
T* chain<T>::operator[](const unsigned int index)
{
	return const_cast<T*>(static_cast<const chain<T>&>(*this)[index]);
}

template <typename T>
const T* chain<T>::operator[](const unsigned int index) const
{
    assert(index < m_size);

    T* it = m_head;
    for (unsigned int i = 0; i != index; ++i, it = it->next);
	
    return it;
}

template <typename T>
T* chain<T>::front()
{
    return const_cast<T*>(static_cast<const chain<T>&>(*this).front());
}

template <typename T>
const T* chain<T>::front() const
{
    return m_head;
}

template <typename T>
T* chain<T>::back()
{
    return const_cast<T*>(static_cast<const chain<T>&>(*this).back());
}

template <typename T>
const T* chain<T>::back() const
{
    T* it = m_head;
    for (; it->next != nullptr; it = it->next);

    return it;
}

template <typename T>
void chain<T>::push_front(T* object)
{
    insert(object, 0);
}

template <typename T>
void chain<T>::push_back(T* object)
{
    insert(object, size());
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
void chain<T>::insert(T* object, unsigned int index)
{
    // Less or equal, because we may be inserting as last element.
    assert(index <= m_size);

    object->next = nullptr;
    ++m_size;

    if (index == 0) {
        object->next = m_head;
        m_head = object;
        return;
    }

    T* it = m_head;
    for (unsigned int i = 0; i != (index - 1); ++i, it = it->next);

    object->next = it->next;
    it->next = object;
}

template <typename T>
void chain<T>::insert(chain<T>& other)
{
    while (other.size() > 0)
        push_back(other.pop_front());
}

template <typename T>
T* chain<T>::remove(unsigned int index)
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
    for (unsigned int i = 0; i != (index - 1); ++i, it = it->next);

    T* result = it->next;
    it->next = it->next->next;
    return result;
}

template <typename T>
unsigned int chain<T>::size()
{
    return m_size;
}

template <typename T>
int chain<T>::indexOf(T* object)
{
    T* it = m_head;
    for (unsigned int i = 0; i < m_size; ++i, it = it->next) {
        if (it == object)
            return i;
    }

    return -1;
}

} // namespace os

#endif 

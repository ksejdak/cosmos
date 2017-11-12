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

#ifndef BUDDY_ALLOCATOR_H
#define BUDDY_ALLOCATOR_H

#include "allocator.h"
#include "page.h"
#include "pagepool.h"

#include <os/chain.h>
#include <os/pair.h>

#include <cstdint>

namespace Memory {

class MemoryChunk : public os::IChainable<MemoryChunk> {
public:
    MemoryChunk();

    bool checkMagic();
    std::uint32_t virtualAddress();
    void* data();
    std::uint16_t size();
    Page* parentPage();

    void init(Page* parentPage);
    void setVirtualAddress(std::uint32_t virtualAddress);
    void setSize(std::uint32_t size);

    os::pair<MemoryChunk, MemoryChunk> split();

private:
    std::uint32_t m_magic;
    std::uint32_t m_virtualAddress;
    std::uint32_t m_size;
    Page* m_parentPage;
} __attribute__ ((packed));

class BuddyAllocator : public IAllocator {
public:
    BuddyAllocator();

    virtual void* allocate(std::uint32_t size);
    virtual void release(void *memoryChunk);

private:
    bool allocatePage();
    int sizeToFactor(std::uint32_t size);
    std::uint32_t factorToSize(int factor);
    void splitChunk(MemoryChunk* chunk);

private:
    static const int MEMORY_CHUNK_FACTOR = 13;

    os::chain<MemoryChunk> m_freeChunks[MEMORY_CHUNK_FACTOR];
};

} // namespace Memory

#endif

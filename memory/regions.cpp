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

#include "regions.h"

#include <cassert>

extern int _memoryRegions_pa;

namespace Memory {

MemoryRegions::MemoryRegions()
    : m_regions(reinterpret_cast<MemoryRegionEntry *>(&_memoryRegions_pa))
    , m_count(0)
{
    for (auto it = m_regions; it->totalSize != 0; ++it)
        ++m_count;
}

int MemoryRegions::count()
{
    return m_count;
}

std::uint32_t MemoryRegions::physicalAddress(int index)
{
    assert(index < m_count);
    return m_regions[index].physicalAddress;
}

std::uint32_t MemoryRegions::totalSize(int index)
{
    assert(index < m_count);
    return m_regions[index].totalSize;
}

std::uint32_t MemoryRegions::usedSize(int index)
{
    assert(index < m_count);
    return m_regions[index].usedSize;
}

} // namespace Memory

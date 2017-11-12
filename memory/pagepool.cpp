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

#include "pagepool.h"
#include "regions.h"

#include <hal/mmu.h>

extern int _pagePoolStart_pa;

using namespace HAL;

namespace Memory {

PagePool::PagePool()
{
    // Check, that initial page starts at the beginning of first region.
    std::uint32_t initialPagePA = (std::uint32_t) &_pagePoolStart_pa;
    MemoryRegions& regions = MemoryRegions::instance();
    assert(initialPagePA == regions.physicalAddress(0));

    m_initialPage.setPhysicalAddress(initialPagePA);
    m_allPages.push_back(&m_initialPage);

    m_pagesCount = m_allPages.size();
    m_freePagesCount = m_pagesCount;
}

bool PagePool::init()
{
    MemoryRegions& regions = MemoryRegions::instance();
    for (int i = 0; i < regions.count(); ++i) {
        std::uint32_t regionEndPA = regions.physicalAddress(i) + regions.totalSize(i);
        std::uint32_t regionUsedEndPA = regions.physicalAddress(i) + regions.usedSize(i);

        for (std::uint32_t address = regions.physicalAddress(i); address + IMMU::pageSize() < regionEndPA; address += IMMU::pageSize()) {
            if (address == regions.physicalAddress(0)) {
                // Skip address describing initial page. We already have it.
                continue;
            }

            Page* page = new Page(address);
            page->setOccupied();

            ++m_pagesCount;
            if (address >= regionUsedEndPA) {
                page->setFree();
                ++m_freePagesCount;
            }

            m_allPages.push_back(page);
        }
    }

    return true;
}

os::chain<Page> PagePool::allocatePages(unsigned int count)
{
    os::chain<Page> pages;
    if (m_freePagesCount < count)
        return pages;

    for (unsigned int i = 0; i < count; ++i) {
        for (unsigned int j = 0; j < m_pagesCount; ++j) {
            if (!m_allPages[j]->isOccupied()) {
                m_allPages[j]->setOccupied();
                pages.push_back(m_allPages[j]);
            }
        }
    }

    return pages;
}

void PagePool::releasePages(os::chain<Page>& pages)
{
    while (pages.size() > 0) {
        for (unsigned int i = 0; i < m_pagesCount; ++i) {
            if (m_allPages[i]->physicalAddress() != pages[i]->physicalAddress())
                assert(false);

            pages[i]->setFree();
            pages.pop_back();
        }
    }
}

unsigned int PagePool::pagesCount()
{
    return m_pagesCount;
}

unsigned int PagePool::freePagesCount()
{
    return m_freePagesCount;
}

} // namespace Memory

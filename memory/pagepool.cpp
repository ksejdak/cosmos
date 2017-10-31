////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       28.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

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

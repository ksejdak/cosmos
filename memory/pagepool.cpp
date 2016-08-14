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

extern int _pagePoolStart_pa;

namespace Memory {

PagePool::PagePool()
    : m_pagesCount(1)
    , m_freePagesCount(m_pagesCount)
{
    m_initialPage.setPhysicalAddress((uint32_t) &_pagePoolStart_pa);
    m_allPages.push_back(&m_initialPage);
}

bool PagePool::init()
{
    /// @todo Initialize rest of memory.
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

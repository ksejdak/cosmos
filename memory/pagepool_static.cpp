////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "pagepool_static.h"

#include <hal/mmu.h>
#include <os/assert.h>

using namespace HAL;

extern int _pagePoolSize;

namespace Memory {

bool StaticPagePool::init()
{
    int realPoolPagesCount = _pagePoolSize / IMMU::getPageSize();
    assert(PAGE_POOL_PAGES_COUNT == realPoolPagesCount);

    m_pagesCount = realPoolPagesCount;
    m_freePagesCount = m_pagesCount;
    return true;
}

os::chain<PhysicalPage> StaticPagePool::allocatePages(unsigned int count)
{
    os::chain<PhysicalPage> pages;
    if (m_freePagesCount < count)
        return pages;

    for (unsigned int i = 0; i < count; ++i) {
        for (unsigned int j = 0; j < m_pagesCount; ++j) {
            if (!m_staticPages[j].isOccupied()) {
                m_staticPages[j].setOccupied();
                pages.push_back(&m_staticPages[j]);
            }
        }
    }

    return pages;
}

void StaticPagePool::releasePages(os::chain<PhysicalPage>& pages)
{
    while (pages.size() > 0) {
        for (unsigned int i = 0; i < m_pagesCount; ++i) {
            if (m_staticPages[i].getPhysicalAddress() != pages[i]->getPhysicalAddress())
                assert(false);

            pages[i]->setFree();
            pages.pop_back();
        }
    }
}

} // namespace Memory

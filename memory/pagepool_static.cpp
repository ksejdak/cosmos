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

using namespace Memory;

extern int _pagePoolSize;

int StaticPagePool::PAGE_POOL_PAGES_COUNT = _pagePoolSize / IMemoryManagementUnit::getPageSize();

bool StaticPagePool::init()
{
    // Nothing fancy to do here.
    return true;
}

PhysicalPage* StaticPagePool::allocatePage()
{
    for (int i = 0; i < PAGE_POOL_PAGES_COUNT; ++i) {
        if (!m_staticPages[i].isOccupied()) {
            m_staticPages[i].setOccupied();
            return &m_staticPages[i];
        }
    }

    return nullptr;
}

void StaticPagePool::releasePage(PhysicalPage* page)
{
    for (int i = 0; i < PAGE_POOL_PAGES_COUNT; ++i) {
        if (m_staticPages[i].physicalAddress() == page->physicalAddress()) {
            page->setFree();
            return;
        }
    }

    assert(false);
}

int StaticPagePool::getPagesCount()
{
    return PAGE_POOL_PAGES_COUNT;
}

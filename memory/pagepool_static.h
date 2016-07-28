////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PAGEPOOL_STATIC_H
#define PAGEPOOL_STATIC_H

#include "pagepool.h"

namespace Memory {

class StaticPagePool : public IPagePool {
public:
    virtual bool init();

    virtual os::chain<PhysicalPage> allocatePages(unsigned int count);
    virtual void releasePages(os::chain<PhysicalPage>& pages);

private:
    static const unsigned int PAGE_POOL_PAGES_COUNT = 4;

    PhysicalPage m_staticPages[PAGE_POOL_PAGES_COUNT];
};

} // namespace Memory

#endif

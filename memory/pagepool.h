////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PAGEPOOL_H
#define PAGEPOOL_H

#include "page.h"

#include <os/chain.h>

namespace Memory {

class IPagePool {
public:
    IPagePool();

    virtual bool init() = 0;
    virtual os::chain<Page> allocatePages(unsigned int count) = 0;
    virtual void releasePages(os::chain<Page>& pages) = 0;

    unsigned int getPagesCount();
    unsigned int getFreePagesCount();

protected:
    unsigned int m_pagesCount;
    unsigned int m_freePagesCount;
};

} // namespace Memory

#endif

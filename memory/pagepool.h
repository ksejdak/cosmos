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

class PagePool {
public:
    static PagePool& instance()
    {
        static PagePool object;
        return object;
    }

    bool init();
    os::chain<Page> allocatePages(unsigned int count);
    void releasePages(os::chain<Page>& pages);

    unsigned int pagesCount();
    unsigned int freePagesCount();

private:
    PagePool();

private:
    Page m_initialPage;
    os::chain<Page> m_allPages;

    unsigned int m_pagesCount;
    unsigned int m_freePagesCount;
};

} // namespace Memory

#endif

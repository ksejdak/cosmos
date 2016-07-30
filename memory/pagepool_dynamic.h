////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PAGEPOOL_DYNAMIC_H
#define PAGEPOOL_DYNAMIC_H

#include "pagepool.h"

namespace Memory {

class DynamicPagePool : public IPagePool {
public:
    virtual bool init();

    virtual os::chain<Page> allocatePages(unsigned int count);
    virtual void releasePages(os::chain<Page>& pages);
};

} // namespace Memory

#endif

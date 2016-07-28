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

namespace Memory {

IPagePool::IPagePool()
    : m_pagesCount(0)
    , m_freePagesCount(m_pagesCount)
{
}

unsigned int IPagePool::getPagesCount()
{
    return m_pagesCount;
}

unsigned int IPagePool::getFreePagesCount()
{
    return m_freePagesCount;
}

} // namespace Memory

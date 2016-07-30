////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       20.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PAGE_H
#define PAGE_H

#include <os/chain.h>
#include <os/stdint.h>

namespace Memory {

class Page : public os::IChainable<Page> {
public:
    // Pages should be allocated by static allocator.
    void* operator new(unsigned int size);
    void operator delete(void* pointer);

    Page();
    Page(uint32_t physicalAddress);

    uint32_t getPhysicalAddress();
    bool isOccupied();
    void setOccupied();
    void setFree();

private:
    uint32_t m_physicalAddress;
    bool m_occupied;
};

} // namespace Memory

#endif

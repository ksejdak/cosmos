////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       16.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include <hal/mmu.h>
#include <os/stdint.h>

// Disable function name mangling.
extern "C" {

void __attribute__ ((section (".boot"))) mmu_init()
{
}

} // extern "C"

using namespace HAL;

int IMemoryManagementUnit::getPageSize()
{
    return 4 * 1024;
}

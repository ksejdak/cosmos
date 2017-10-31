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

extern "C" {

void __attribute__ ((section (".boot"))) mmu_init()
{
}

} // extern "C"

namespace HAL {

std::uint32_t IMMU::pageSize()
{
    return 4 * 1024;
}

} // namespace HAL


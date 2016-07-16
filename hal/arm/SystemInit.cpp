////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       16.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

extern int _bssStart_lma;
extern int _bssEnd_lma;

// Disable function name mangling.
extern "C" {

void __attribute__ ((section (".boot"))) SystemInit()
{
    // Clear .bss section.
    for (uint16_t *it = reinterpret_cast<uint16_t *>(_bssStart_lma); it != reinterpret_cast<uint16_t *>(_bssEnd_lma); ++it)
        *it = 0;
}

} // extern "C"
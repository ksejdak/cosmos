////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BEAGLEBONE_BLACK_H
#define BEAGLEBONE_BLACK_H

#include <board/board.h>

namespace Board {

class BeagleBoneBlack : public IBoard {
public:
    BeagleBoneBlack();

    virtual bool initDevice();

private:
    bool initUserLED();
    bool initConsole();
};

} // namespace Board

#endif

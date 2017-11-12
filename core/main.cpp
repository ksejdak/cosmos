////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       17.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include <board/board.h>
#include <memory/allocator.h>

#include <cstdio>

using namespace Board;
using namespace Memory;

int main()
{
    IAllocator::init();
    IBoard::init();

    printf("Hello World!\n");
    return 0;
}

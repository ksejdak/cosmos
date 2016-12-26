////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "board.h"

namespace Board {

bool IBoard::init()
{
    return instance()->initDevice();
}

IBoard::IBoard()
    : m_name(nullptr)
    , m_vendor(nullptr)
    , m_version(nullptr)
{
}

} // namespace Board

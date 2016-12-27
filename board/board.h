////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BOARD_H
#define BOARD_H

namespace Board {

class IBoard {
public:
    static IBoard* instance() {
        static IBoard* object = create();
        return object;
    }

    static bool init();
    virtual bool initDevice() = 0;

protected:
    static IBoard* create();
    IBoard();

protected:
    const char *m_name;
    const char *m_vendor;
    const char *m_version;
};

} // namespace Board

#endif

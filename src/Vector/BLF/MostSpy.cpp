/*
 * Copyright (C) 2013 Tobias Lorenz.
 * Contact: tobias.lorenz@gmx.net
 *
 * This file is part of Tobias Lorenz's Toolkit.
 *
 * Commercial License Usage
 * Licensees holding valid commercial licenses may use this file in
 * accordance with the commercial license agreement provided with the
 * Software or, alternatively, in accordance with the terms contained in
 * a written agreement between you and Tobias Lorenz.
 *
 * GNU General Public License 3.0 Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl.html.
 */

#include "MostSpy.h"

#include <cstring>

namespace Vector {
namespace BLF {

MostSpy::MostSpy() :
    ObjectHeader(),
    channel(),
    dir(),
    dummy1(),
    sourceAdr(),
    destAdr(),
    msg(),
    dummy2(),
    rTyp(),
    rTypAdr(),
    state(),
    dummy3(),
    ackNack(),
    crc()
{
}

char * MostSpy::parse(char * buffer)
{
    size_t size;

    // previous data
    buffer = ObjectHeader::parse(buffer);

    // channel
    size = sizeof(channel);
    memcpy((char *) &channel, buffer, size);
    buffer += size;

    // dir
    size = sizeof(dir);
    memcpy((char *) &dir, buffer, size);
    buffer += size;

    // dummy1
    size = sizeof(dummy1);
    memcpy((char *) &dummy1, buffer, size);
    buffer += size;

    // sourceAdr
    size = sizeof(sourceAdr);
    memcpy((char *) &sourceAdr, buffer, size);
    buffer += size;

    // destAdr
    size = sizeof(destAdr);
    memcpy((char *) &destAdr, buffer, size);
    buffer += size;

    // msg
    size = sizeof(msg);
    memcpy((char *) &msg, buffer, size);
    buffer += size;

    // dummy2
    size = sizeof(dummy2);
    memcpy((char *) &dummy2, buffer, size);
    buffer += size;

    // rTyp
    size = sizeof(rTyp);
    memcpy((char *) &rTyp, buffer, size);
    buffer += size;

    // rTypAdr
    size = sizeof(rTypAdr);
    memcpy((char *) &rTypAdr, buffer, size);
    buffer += size;

    // state
    size = sizeof(state);
    memcpy((char *) &state, buffer, size);
    buffer += size;

    // dummy3
    size = sizeof(dummy3);
    memcpy((char *) &dummy3, buffer, size);
    buffer += size;

    // ackNack
    size = sizeof(ackNack);
    memcpy((char *) &ackNack, buffer, size);
    buffer += size;

    // crc
    size = sizeof(crc);
    memcpy((char *) &crc, buffer, size);
    buffer += size;

    return buffer;
}

size_t MostSpy::calculateObjectSize()
{
    size_t size =
            ObjectHeader::calculateObjectSize() +
            sizeof(channel) +
            sizeof(dir) +
            sizeof(dummy1) +
            sizeof(sourceAdr) +
            sizeof(destAdr) +
            sizeof(msg) +
            sizeof(dummy2) +
            sizeof(rTyp) +
            sizeof(rTypAdr) +
            sizeof(state) +
            sizeof(dummy3) +
            sizeof(ackNack) +
            sizeof(crc);

    return size;
}

}
}

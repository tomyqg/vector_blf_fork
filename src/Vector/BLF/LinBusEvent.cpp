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

#include "LinBusEvent.h"

#include <cstring>

namespace Vector {
namespace BLF {

LinBusEvent::LinBusEvent() :
    sof(),
    eventBaudrate(),
    channel(),
    reserved()
{
}

char * LinBusEvent::parse(char * buffer)
{
    size_t size;

    // sof
    size = sizeof(sof);
    memcpy((void *) &sof, buffer, size);
    buffer += size;

    // eventBaudrate
    size = sizeof(eventBaudrate);
    memcpy((void *) &eventBaudrate, buffer, size);
    buffer += size;

    // channel
    size = sizeof(channel);
    memcpy((void *) &channel, buffer, size);
    buffer += size;

    // reserved
    size = sizeof(reserved);
    memcpy((void *) &reserved, buffer, size);
    buffer += size;

    return buffer;
}

size_t LinBusEvent::calculateObjectSize()
{
    size_t size =
            sizeof(sof) +
            sizeof(eventBaudrate) +
            sizeof(channel) +
            sizeof(reserved);

    return size;
}

}
}

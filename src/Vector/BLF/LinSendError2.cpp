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

#include "LinSendError2.h"

#include <cstring>

namespace Vector {
namespace BLF {

LinSendError2::LinSendError2() :
    ObjectHeader(),
    LinMessageDescriptor(),
    eoh(),
    isEtf(),
    fsmId(),
    fsmState(),
    reserved1(),
    reserved2(),
    exactHeaderBaudrate(),
    earlyStopbitOffset()
{
}

char * LinSendError2::parse(char * buffer)
{
    size_t size;

    // previous data
    buffer = ObjectHeader::parse(buffer);
    buffer = LinMessageDescriptor::parse(buffer);

    // eoh
    size = sizeof(eoh);
    memcpy((void *) &eoh, buffer, size);
    buffer += size;

    // isEtf
    size = sizeof(isEtf);
    memcpy((void *) &isEtf, buffer, size);
    buffer += size;

    // fsmId
    size = sizeof(fsmId);
    memcpy((void *) &fsmId, buffer, size);
    buffer += size;

    // fsmState
    size = sizeof(fsmState);
    memcpy((void *) &fsmState, buffer, size);
    buffer += size;

    // reserved1
    size = sizeof(reserved1);
    memcpy((void *) &reserved1, buffer, size);
    buffer += size;

    // reserved2
    size = sizeof(reserved2);
    memcpy((void *) &reserved2, buffer, size);
    buffer += size;

    // exactHeaderBaudrate
    size = sizeof(exactHeaderBaudrate);
    memcpy((void *) &exactHeaderBaudrate, buffer, size);
    buffer += size;

    // earlyStopbitOffset
    size = sizeof(earlyStopbitOffset);
    memcpy((void *) &earlyStopbitOffset, buffer, size);
    buffer += size;

    return buffer;
}

size_t LinSendError2::calculateObjectSize()
{
    size_t size =
            ObjectHeader::calculateObjectSize() +
            LinMessageDescriptor::calculateObjectSize() +
            sizeof(eoh) +
            sizeof(isEtf) +
            sizeof(fsmId) +
            sizeof(fsmState) +
            sizeof(reserved1) +
            sizeof(reserved2) +
            sizeof(exactHeaderBaudrate) +
            sizeof(earlyStopbitOffset);

    return size;
}

}
}

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

#pragma once

#include "VectorTypes.h"
#include "ObjectHeader.h"

#include "vector_blf_export.h"

namespace Vector {
namespace BLF {

/**
 * @brief FLEXRAY_SYNC
 *
 * @deprecated
 */
class VECTOR_BLF_EXPORT FlexRaySync : public ObjectHeader
{
public:
    FlexRaySync();

    virtual char * parse(char * buffer);
    virtual size_t calculateObjectSize();

    /**
     * @brief application channel
     */
    WORD channel;

    /** multiplexer */
    BYTE mux;

    /** length */
    BYTE len;

    /** message id */
    WORD messageId;

    /** CRC */
    WORD crc;

    /** direction */
    BYTE dir;

    /** reserved */
    BYTE reserved[3];

    /** data bytes */
    BYTE dataBytes[11];

    /** cycle */
    BYTE cycle;
};

}
}

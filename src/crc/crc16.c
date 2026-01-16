#include "srp/crc/crc.h"

#include <stdint.h>

uint16_t crc16_ccitt(const uint8_t *data, size_t length)
{
    uint16_t crc = CRC16_CCITT_INITIAL_VALUE;
    uint8_t e;
    uint8_t f;

    if (data == NULL) {
        return crc;
    }

    for (; length > 0; length--) {
        e = crc ^ *data;
        data++;
        f = e ^ (e << 4);
        crc = (crc >> 8) ^ ((uint16_t)f << 8) ^ ((uint16_t)f << 3) ^ ((uint16_t)f >> 4);
    }

    return crc;
}

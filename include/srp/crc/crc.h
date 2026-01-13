#ifndef SRP_CRC_H
#define SRP_CRC_H

#include <stddef.h>
#include <stdint.h>

uint16_t crc16_ccitt(const uint8_t *data, size_t size);

#endif // SRP_CRC_H

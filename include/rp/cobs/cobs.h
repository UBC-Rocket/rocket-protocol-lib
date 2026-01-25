#ifndef RP_COBS_H
#define RP_COBS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum cobs_result {
    COBS_OK,
    COBS_INVALID,
    COBS_OVERFLOW,
} cobs_result_t;

cobs_result_t cobs_encode(const uint8_t *data, size_t data_size, uint8_t *output,
                          size_t output_capacity);

cobs_result_t cobs_decode(const uint8_t *data, size_t data_size, uint8_t *output,
                          size_t output_capacity);

#endif // RP_COBS_H

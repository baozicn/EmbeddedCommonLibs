#ifndef CRC16_H
#define CRC16_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Compute CRC-16 (CRC-CCITT, polynomial 0x1021) on a byte buffer.
 *
 * @param data Pointer to the data buffer
 * @param length Number of bytes in the buffer
 * @param initial Initial CRC value (use 0xFFFF for new calculations)
 * @return Computed CRC-16 value
 */
uint16_t crc16_compute(const uint8_t *data, uint32_t length, uint16_t initial);

#ifdef __cplusplus
}
#endif

#endif /* CRC16_H */

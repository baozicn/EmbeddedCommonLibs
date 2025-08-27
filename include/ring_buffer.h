#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Ring buffer structure.
 */
typedef struct {
    uint8_t *buffer;   /**< Pointer to buffer memory */
    uint16_t head;     /**< Head index */
    uint16_t tail;     /**< Tail index */
    uint16_t size;     /**< Total size of buffer */
} ring_buffer_t;

/**
 * @brief Initialize ring buffer.
 *
 * @param rb Pointer to ring buffer structure
 * @param buf Memory buffer array
 * @param size Size of the buffer array
 */
void ring_buffer_init(ring_buffer_t *rb, uint8_t *buf, uint16_t size);

/**
 * @brief Put a byte into the ring buffer.
 *
 * @param rb Ring buffer
 * @param data Byte to insert
 * @return true on success, false if buffer is full
 */
bool ring_buffer_put(ring_buffer_t *rb, uint8_t data);

/**
 * @brief Get a byte from the ring buffer.
 *
 * @param rb Ring buffer
 * @param data Pointer to variable to receive the byte
 * @return true on success, false if buffer is empty
 */
bool ring_buffer_get(ring_buffer_t *rb, uint8_t *data);

/**
 * @brief Check if ring buffer is empty.
 *
 * @param rb Ring buffer
 * @return true if empty, false otherwise
 */
bool ring_buffer_is_empty(ring_buffer_t *rb);

/**
 * @brief Check if ring buffer is full.
 *
 * @param rb Ring buffer
 * @return true if full, false otherwise
 */
bool ring_buffer_is_full(ring_buffer_t *rb);

/**
 * @brief Get number of bytes currently stored in ring buffer.
 *
 * @param rb Ring buffer
 * @return Number of bytes in buffer
 */
uint16_t ring_buffer_count(const ring_buffer_t *rb);

#ifdef __cplusplus
}
#endif

#endif // RING_BUFFER_H

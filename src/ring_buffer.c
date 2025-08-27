#include "ring_buffer.h"

void ring_buffer_init(ring_buffer_t *rb, uint8_t *buf, uint16_t size) {
    rb->buffer = buf;
    rb->size = size;
    rb->head = 0;
    rb->tail = 0;
}

bool ring_buffer_put(ring_buffer_t *rb, uint8_t data) {
    uint16_t next = (rb->head + 1) % rb->size;
    if (next == rb->tail) {
        return false; // Buffer full
    }
    rb->buffer[rb->head] = data;
    rb->head = next;
    return true;
}

bool ring_buffer_get(ring_buffer_t *rb, uint8_t *data) {
    if (rb->head == rb->tail) {
        return false; // Buffer empty
    }
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % rb->size;
    return true;
}

bool ring_buffer_is_empty(ring_buffer_t *rb) {
    return rb->head == rb->tail;
}

bool ring_buffer_is_full(ring_buffer_t *rb) {
    return ((rb->head + 1) % rb->size) == rb->tail;
}

uint16_t ring_buffer_count(ring_buffer_t *rb) {
    if (rb->head >= rb->tail) {
        return rb->head - rb->tail;
    } else {
        return rb->size - rb->tail + rb->head;
    }
}

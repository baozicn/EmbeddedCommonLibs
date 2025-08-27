#include <stdio.h>
#include "ring_buffer.h"

#define BUFFER_SIZE 8

int main(void)
{
    uint8_t buffer[BUFFER_SIZE];
    ring_buffer_t rb;
    ring_buffer_init(&rb, buffer, BUFFER_SIZE);

    // Enqueue some values
    for (uint8_t i = 0; i < 5; ++i) {
        if (ring_buffer_put(&rb, i)) {
            printf("Enqueued %u\n", i);
        } else {
            printf("Queue full, failed to enqueue %u\n", i);
        }
    }

    // Dequeue all values
    while (!ring_buffer_is_empty(&rb)) {
        uint8_t value;
        if (ring_buffer_get(&rb, &value)) {
            printf("Dequeued %u\n", value);
        }
    }

    return 0;
}

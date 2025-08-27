#include "delay.h"

void delay_us(unsigned int us)
{
    // Simple busy-wait loop for microsecond delay (approximate)
    while (us--) {
        // Adjust the number of iterations to match your MCU speed
        for (volatile unsigned int i = 0; i < 10; ++i) {
            __asm__ volatile ("nop");
        }
    }
}

void delay_ms(unsigned int ms)
{
    while (ms--) {
        delay_us(1000U);
    }
}

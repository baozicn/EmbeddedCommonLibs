#include "crc16.h"

uint16_t crc16_compute(const uint8_t *data, uint32_t length, uint16_t initial)
{
    uint16_t crc = initial;
    for (uint32_t i = 0; i < length; i++)
    {
        crc ^= ((uint16_t)data[i] << 8);
        for (uint8_t j = 0; j < 8; j++)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ 0x1021;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

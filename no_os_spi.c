#include "no_os_spi.h"
#include <stdio.h>

// Mock implementation of SPI initialization
int32_t no_os_spi_init(struct no_os_spi_init_param *param) {
    printf("Mock SPI init: Device ID: %d, Max Speed: %d, Chip Select: %d, Mode: %d\n",
           param->device_id, param->max_speed_hz, param->chip_select, param->mode);
    return 0; // Return success
}

// Mock implementation of SPI write
int32_t no_os_spi_write(uint8_t reg, uint8_t data) {
    printf("Mock SPI write: Register: 0x%02X, Data: 0x%02X\n", reg, data);
    return 0; // Return success
}

// Mock implementation of SPI read
int32_t no_os_spi_read(uint8_t reg, uint8_t *data) {
    *data = 0xFF; // Return dummy data
    printf("Mock SPI read: Register: 0x%02X, Data: 0x%02X\n", reg, *data);
    return 0; // Return success
}

// Mock implementation of SPI cleanup
void no_os_spi_remove() {
    printf("Mock SPI remove: SPI resources cleaned up\n");
}

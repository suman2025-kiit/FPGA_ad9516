
#ifndef NO_OS_SPI_MODE_0
#define NO_OS_SPI_MODE_0 0  // SPI mode 0
#endif
#ifndef NO_OS_SPI_H
#define NO_OS_SPI_H


#include <stdint.h>

// SPI initialization parameters
struct no_os_spi_init_param {
    uint8_t device_id;       // SPI device ID
    uint32_t max_speed_hz;   // Max SPI clock speed
    uint8_t chip_select;     // Chip select
    uint8_t mode;            // SPI mode
};

// Function prototypes
int32_t no_os_spi_init(struct no_os_spi_init_param *param);
int32_t no_os_spi_write(uint8_t reg, uint8_t data);
int32_t no_os_spi_read(uint8_t reg, uint8_t *data);
void no_os_spi_remove();

#endif // NO_OS_SPI_H

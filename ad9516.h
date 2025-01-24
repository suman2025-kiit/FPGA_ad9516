#ifndef AD9516_REG_PART_ID
#define AD9516_REG_PART_ID 0x003  // Register address for Part ID
#endif

#ifndef AD9516_H
#define AD9516_H

#include <stdint.h>
#include "no_os_spi.h" // Include SPI initialization parameters

/* AD9516 Register Map */
#define AD9516_REG_PART_ID      0x003  // Register address for Part ID
#define AD9516_REG_CLOCK_DIV    0x004  // Example: Clock divider register (if needed)

/* AD9516 Device Types */
#define AD9516_0 0x01  // Part ID for AD9516-0
#define AD9516_1 0x41  // Part ID for AD9516-1
#define AD9516_2 0x81  // Part ID for AD9516-2
#define AD9516_3 0x43  // Part ID for AD9516-3
#define AD9516_4 0xC3  // Part ID for AD9516-4

/* AD9516 Initialization Parameters */
struct ad9516_init_param {
    struct no_os_spi_init_param spi_init; // SPI initialization parameters
    uint8_t ad9516_type;                 // Device type (e.g., AD9516_1)
};

/* AD9516 Device Descriptor */
struct ad9516_dev {
    struct no_os_spi_init_param spi_desc; // SPI descriptor for the device
    uint8_t device_type;                  // Device type (e.g., AD9516_1)
};

/* Function Prototypes */

/**
 * @brief Initializes the AD9516 device.
 * @param[out] device - Pointer to the device instance.
 * @param[in] init_param - Initialization parameters for the device.
 * @return 0 in case of success, negative error code otherwise.
 */
int32_t ad9516_setup(struct ad9516_dev **device, struct ad9516_init_param init_param);

/**
 * @brief Reads a register from the AD9516 device.
 * @param[in] device - Pointer to the device instance.
 * @param[in] reg - Register address to read from.
 * @param[out] data - Pointer to store the read data.
 * @return 0 in case of success, negative error code otherwise.
 */
int32_t ad9516_read(struct ad9516_dev *device, uint32_t reg, uint32_t *data);

/**
 * @brief Removes the AD9516 device and cleans up resources.
 * @param[in] device - Pointer to the device instance.
 */
void ad9516_remove(struct ad9516_dev *device);

#endif // AD9516_H

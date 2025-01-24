#include "xparameters.h"  // For XPAR_AXI_QUAD_SPI_0_DEVICE_ID
#include "no_os_spi.h"    // For NO_OS_SPI_MODE_0
#include "ad9516.h"       // For AD9516 constants and functions
#include <stdio.h>


/* Main function for C simulation */
int main() {
    struct ad9516_dev *ad9516_device;
    struct ad9516_init_param init_param = {
        .spi_init = {
            .device_id = XPAR_AXI_QUAD_SPI_0_DEVICE_ID,
            .max_speed_hz = 1000000,
            .chip_select = 0,
            .mode = NO_OS_SPI_MODE_0
        },
        .ad9516_type = AD9516_1
    };
    uint32_t reg_value = 0;
    int32_t status;

    // Enable cache
    Xil_ICacheEnable();
    Xil_DCacheEnable();
    printf("---Entering main---\n");

    // Initialize AD9516
    status = ad9516_setup(&ad9516_device, init_param);
    if (status != 0) {
        printf("Failed to initialize AD9516. Error code: %d\n", status);
        return -1;
    }

    // Read Part ID
    status = ad9516_read(ad9516_device, AD9516_REG_PART_ID, &reg_value);
    if (status != 0) {
        printf("Failed to read Part ID. Error code: %d\n", status);
        ad9516_remove(ad9516_device);
        return -1;
    }

    printf("Register 0x003 (Part ID): 0x%02X\n", reg_value);

    // Validate Part ID
    if (reg_value != AD9516_1) {
        printf("Part ID mismatch. Expected: 0x%02X, Got: 0x%02X\n", AD9516_1, reg_value);
        ad9516_remove(ad9516_device);
        return -1;
    }

    printf("AD9516-1 identified successfully with Part ID: 0x%02X\n", reg_value);

    // Cleanup
    ad9516_remove(ad9516_device);
    printf("---Exiting main---\n");

    // Disable cache
    Xil_DCacheDisable();
    Xil_ICacheDisable();

    return 0;
}

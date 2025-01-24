#include "ad9516.h"
#include <stdio.h>

// Mock implementation of ad9516_setup
int32_t ad9516_setup(struct ad9516_dev **device, struct ad9516_init_param init_param) {
    static struct ad9516_dev dev; // Mock device instance
    dev.device_type = init_param.ad9516_type;
    *device = &dev;
    printf("Mock ad9516_setup: Device initialized with type 0x%02X\n", dev.device_type);
    return 0; // Return success
}

// Mock implementation of ad9516_read
int32_t ad9516_read(struct ad9516_dev *device, uint32_t reg, uint32_t *data) {
    if (reg == 0x003) {
        *data = 0x41; // Mock Part ID for AD9516-1
        printf("Mock ad9516_read: Register 0x%03X, Data 0x%02X\n", reg, *data);
        return 0; // Return success
    }
    return -1; // Return error for invalid register
}

// Mock implementation of ad9516_remove
void ad9516_remove(struct ad9516_dev *device) {
    printf("Mock ad9516_remove: Device removed\n");
}

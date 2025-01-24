#include "xil_cache.h"
#include <stdio.h>

void Xil_ICacheEnable(void) {
    printf("Instruction Cache Enabled\n");
}

void Xil_ICacheDisable(void) {
    printf("Instruction Cache Disabled\n");
}

void Xil_DCacheEnable(void) {
    printf("Data Cache Enabled\n");
}

void Xil_DCacheDisable(void) {
    printf("Data Cache Disabled\n");
}

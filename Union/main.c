#include <stdint.h>
#include <stdio.h>

union Address {
    uint16_t short_address;
    uint32_t long_address;
};

int main(void) {
    union Address device_address;

    device_address.short_address = 0xABCD;
    device_address.long_address = 0xEEEECCCC;

    printf("Short Address = %#X\n", device_address.short_address);
    printf("Long Address  = %#X\n", device_address.long_address);

    return 0;
}

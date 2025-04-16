#include <stdio.h>

// Global variable holding a 64-bit hexadecimal value
long long int global_data = 0xFFFEABCD11112345;  

int main(void) 
{
    // Read as a single byte (char)
    char *byte_ptr = (char*)&global_data;
    printf("Value at address %p (byte): 0x%x\n", byte_ptr, *byte_ptr);

    // Read as a 32-bit integer (int)
    int *int_ptr = (int*)&global_data;
    printf("Value at address %p (int):   0x%x\n", int_ptr, *int_ptr);

    // Read as a 16-bit short (short)
    short *short_ptr = (short*)&global_data;
    printf("Value at address %p (short): 0x%x\n", short_ptr, *short_ptr);

    // Read as the full 64-bit value (long long)
    long long *ll_ptr = (long long*)&global_data;
    printf("Value at address %p (long long): 0x%llx\n", ll_ptr, *ll_ptr);

    return 0;
}
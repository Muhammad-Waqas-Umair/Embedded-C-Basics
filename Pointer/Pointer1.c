#include <stdio.h>

long long int global_value = 0xFFFEABCD11112345;

int main(void) 
{
    char *byte_ptr = (char*)&global_value;
    printf("Value at address %p (byte, size: %zu): 0x%x\n", byte_ptr, sizeof(char), *byte_ptr);

    int *int_ptr = (int*)&global_value;
    printf("Value at address %p (int, size: %zu): 0x%x\n", int_ptr, sizeof(int), *int_ptr);

    short *short_ptr = (short*)&global_value;
    printf("Value at address %p (short, size: %zu): 0x%x\n", short_ptr, sizeof(short), *short_ptr);

    long long *ll_ptr = (long long*)&global_value;
    printf("Value at address %p (long long, size: %zu): 0x%llx\n", ll_ptr, sizeof(long long), *ll_ptr);

    return 0;
}
